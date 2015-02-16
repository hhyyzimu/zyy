#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <glob.h>
#include <string.h>
#include <errno.h>
#include <proto.h>
//#include "../include/proto.h"
#include "medialib.h"

#define NAMESIZE 20
#define PATHSIZE 40

enum
{
	CHN_MELIB_OFF = 0,
	CHN_MELIB_ON
};

struct mlib_chn_context_st
{
	chnid_t chnid;
	char chnfile[NAMESIZE];
	int state;
	glob_t glob;
	int curr;
	int cps;//速率
	pthread_mutex_t mut; //互斥变量
	pthread_cond_t cond; //条件变量
};

static struct mlib_chn_context_st *channels[NR_CHN]; //全局变量
static pthread_once_t init_once = PTHREAD_ONCE_INIT; //只被初始化一次的变量
static pthread_mutex_t mut_channels = PTHREAD_MUTEX_INITIALIZER; //静态初始化互斥变量
static pthread_t tid_alrm; //线程id变量

static void *mlib_alrm(void *p) //信号处理函数，要求等1秒
{
	int i;
	while(1)
	{
		sleep(1);
	}
}

static void module_unload(void) //删除模块
{
	int i;

	pthread_cancel(tid_alrm); //仅发送终止信号给tid_alrm线程
	pthread_join(tid_alrm,NULL); //等待tid_alrm线程结束，不存储返回值，成功的话tid_alrm线程的资源会被收回

	pthread_mutex_lock(&mut_channels); //阻塞的给mut_channels互斥量上锁
	for(i = 0;i < NR_CHN;i++)
	{
		if(channels[i] != NULL)
		{
			pthread_mutex_destroy(&channels[i]->mut); //销毁数据中的互斥变量
			pthread_cond_destroy(&channels[i]->cond); //销毁数据中的条件变量
			free(channels[i]); //释放内存
			channels[i] = NULL; //避免野指针
		}
	}
	pthread_mutex_unlock(&mut_channels); //阻塞的给互斥量mut_channels解锁

	pthread_mutex_destroy(&mut_channels); //销毁互斥变量
}

static void module_load(void) //加载模块
{
	int err;
	err = pthread_create(&tid_alrm,NULL,mlib_alrm,NULL); //创建线程
	if(err)
	{
		fprintf(stderr,"pthread_create():%s\n",strerror(err));
		exit(1);
	}
	atexit(module_unload); //创建一个模块都要在进程结束前进行模块的撤销
}

static int get_free_pos_unlocked(void) //查找空元素并把数据存在空元素的地址中
{
	int i;
	for(i = 0;i < NR_CHN; i++)
		if(channels[i] == NULL)
			return i;
	return -1;
}

int mlib_add_channel(char *pathname,int cps) //增加条目
{
	char nextpath[PATHSIZE];
	int pos;
	int err;
	struct mlib_chn_context_st *me;

	pthread_once(&init_once,module_load); //值初始化一次这个互斥量

	if(pathname == NULL || cps <= 0) //参数无效
		return -EINVAL;

	me = malloc(sizeof(*me)); //参数有效的话给结构体分配地址空间
	if(me == NULL)
		return -ENOMEM;
	
	strncpy(me->chnfile,pathname,PATHSIZE); //给结构体赋值
	strncpy(nextpath,pathname,PATHSIZE);
	strncat(nextpath,"/*",PATHSIZE);
	err = glob(nextpath,0,NULL,&me->glob); //解析nextpath目录
	if(err == GLOB_NOSPACE || err == GLOB_ABORTED) //判断解析出错
	{
		free(me);
		return -EINVAL;
	}
	else if(err == GLOB_NOMATCH)
		me->state = CHN_MELIB_OFF;
	else if(err == 0)
		me->state = CHN_MELIB_ON;
	else
		me->state = CHN_MELIB_OFF;

	me->curr = -1;
	me->cps = cps;
	pthread_mutex_init(&me->mut,NULL); //初始化数据中的互斥变量
	pthread_cond_init(&me->cond,NULL); //初始化数据中的条件变量

	pthread_mutex_lock(&mut_channels); //加锁全局互斥变量
	pos = get_free_pos_unlocked(); //查找空闲的数据地址
	if(pos < 0) //没有空闲数据地址或查找失败
	{
		pthread_mutex_unlock(&mut_channels); //解锁全局互斥变量
		free(me); //释放数据地址
		return -ENOSPC;
	}

	me->chnid = pos; //查找空闲数据地址成功
	channels[pos] = me; 将me的值给这个空闲的数据地址
	pthread_mutex_unlock(&mut_channels); //解锁全局互斥变量
	return pos; //返回这个空闲数据地址
}

int mlib_off_channel(int id)
{
	if(id < 0)
		return -EINVAL;

	pthread_mutex_lock(&mut_channels);
	if(channels[id] == NULL) //如果此频道为空
	{
		pthread_mutex_unlock(&mut_channels);
		return -ESRCH;
	}
	
	pthread_mutex_lock(&channels[id]->mut);
	/*其他情况*/
	if(channels[id]->state == CHN_MELIB_OFF) //如果收音机关闭
	{
		pthread_mutex_unlock(&channels[id]->mut);
		pthread_mutex_unlock(&mut_channels);
		return -ECANCELED;
	}
	channels[id]->state = CHN_MELIB_OFF;
	pthread_cond_broadcast(&channels[id]->cond);

	pthread_mutex_unlock(&channels[id]->mut);
	pthread_mutex_unlock(&mut_channels);

	return 0;
}

static void *thr_wait(void *p)
{
	int id = (int)p;
	pthread_mutex_lock(&mut_channels);
	if(channels[id] == NULL)
	{
		pthread_mutex_unlock(&mut_channels);
		pthread_exit(NULL);
	}
	pthread_mutex_lock(&channels[id]->mut);
	while(channels[id]->state != CHN_MELIB_OFF)
	{
		pthread_mutex_unlock(&mut_channels);
		pthread_cond_wait(&channels[id]->cond,&channels[id]->mut);
		pthread_mutex_lock(&mut_channels);
	}
	pthread_mutex_unlock(&channels[id]->mut);

	pthread_mutex_destroy(&channels[id]->mut);
	pthread_cond_destroy(&channels[id]->cond);
	free(channels[id]);
	channels[id] = NULL;

	pthread_mutex_unlock(&mut_channels);
	pthread_exit(NULL);
}

int mlib_wait_channel(int id)
{
	pthread_t tid;
	int err;

	if(id < 0)
		return -EINVAL;

	err = pthread_create(&tid,NULL,thr_wait,(void *)id);
	if(err)
	{
		fprintf(stderr,"pthread_create():%s\n",strerror(err));
		exit(1);
	}
	pthread_join(tid,NULL);

	return 0;
}
//-------------------------------------------------------------------
//---------------------------------------------------------------------
static int get_chnonnum_unlocked() //查找开着的频道的数目
{
	int num = 0;
	int i;
	for(i = 0; i < NR_CHN; i++)
		if(channels[i] != NULL)
			if(channels[i]->state == CHN_MELIB_ON)
				num++;
	return num;
}
static char *find_txt_unlocked(int pos)
{
	char *des;
	int i;
	if(pos < 0)
		return NULL;

	if(channels[pos] == NULL)
		return NULL;

	for(i = 0; i < (channels[pos]->glob).gl_pathc;i++) //查找目录中.txt的文件
	{
	//	printf("%s\n",(channels[pos]->glob).gl_pathv[i]);
		des = strrchr((channels[pos]->glob).gl_pathv[i],'.');
		if(strcmp(des+1,"txt") == 0)
			return (channels[pos]->glob).gl_pathv[i];
	//	printf("没找到\n");
	}

	return NULL;
}

int mlib_getchnlist(struct mlib_chn_st **chnl,int *chnum)
{
	int i,j;
	char path[PATHSIZE];

	if(*chnl != NULL)
	{
		free(*chnl);
		*chnl = NULL;
	}
	pthread_mutex_lock(&mut_channels);
	*chnum = get_chnonnum_unlocked();

	if(*chnum == 0)
	{
		*chnl = NULL;
		pthread_mutex_unlock(&mut_channels);
		return -ESRCH;
	}

	*chnl = malloc(*chnum * sizeof(struct mlib_chn_st));
//	memset(*chnl,'\0',((chnum)*sizeof(struct mlib_chn_st)));
	j = 0;
	for(i = 0; i < NR_CHN ;i++)
	{
		if(channels[i] != NULL)
		{

			pthread_mutex_lock(&channels[i]->mut);

			if(channels[i]->state == CHN_MELIB_ON)
			{
				(*chnl+j)->chnid = channels[i]->chnid + 1;
			//	printf("%d\n",(*chnl+j)->chnid);
				(*chnl+j)->desc = find_txt_unlocked(i);
			//	printf("%s\n",(*chnl+j)->desc);
				(*chnl+j)->cps = channels[i]->cps;
			//	printf("%d\n",(*chnl+j)->cps);
				j++;
			}
			pthread_mutex_unlock(&channels[i]->mut);
		}
	}

	pthread_mutex_unlock(&mut_channels);
	return 0;
}
int mlib_delchnlist(struct mlib_chn_st * chnlist)
{
	free(chnlist);
	return 0;
}

//----------------------------------------------------------------------
//--------------------------------channel-data----------------------------
static char *find_music_unlocked(int pos)
{
	char *desc;
	int i;

	if(pos < 0 || channels[pos] == NULL || \
			channels[pos]->state != CHN_MELIB_ON)
		return NULL;

	for(i = (channels[pos]->curr + 1); i < (channels[pos]->glob).gl_pathc;\
			i++,(channels[pos]->curr)++)
	{
		desc = strrchr((channels[pos]->glob).gl_pathv[i],'.');
		if(strcmp(desc+1,"txt") != 0)
		{
			channels[pos]->curr++;
			return (channels[pos]->glob).gl_pathv[i];
		}
	}

	return NULL;
}

int mlib_getchndata(struct mlib_chn_st *chnl)
{
	int pos;
	if(chnl == NULL)
		return -EINVAL;
	pos = chnl->chnid - 1;

	pthread_mutex_lock(&mut_channels);
	if(channels[pos] == NULL)
	{
		pthread_mutex_unlock(&mut_channels);
		return -EINVAL;
	}
	pthread_mutex_lock(&channels[pos]->mut);
	chnl->desc = find_music_unlocked(pos);
	chnl->cps = channels[pos]->cps; 
	if((channels[pos]->curr+1) == (channels[pos]->glob).gl_pathc)
//		channels[pos]->state = CHN_MELIB_OFF;
		channels[pos]->curr = -1;
	pthread_cond_broadcast(&channels[pos]->cond);

	pthread_mutex_unlock(&channels[pos]->mut);
	pthread_mutex_unlock(&mut_channels);
	return 0;
}
#if 0
int main()
{
	struct mlib_chn_st *res = NULL,next;
	int num = 0;
	int i;

	next.chnid = 2;
	next.desc = NULL;

	mlib_add_channel(MUSIC,1260000);
	mlib_add_channel(HAO,14900000);

	mlib_getchnlist(&res,&num);

	if(num == 0)
		printf("num=0\n");
	else
	{
		printf("num=%d\n",num);
		for(i=0;i<num;i++)
			printf("reschnid=%d,name=%s,cps=%d\n",(res+i)->chnid,\
					(res+i)->desc,(res+i)->cps);
	}
	mlib_getchndata(&next);

	printf("chnid=%d,name=%s,cps=%d\n",next.chnid,next.desc,next.cps);
	mlib_getchndata(&next);
	printf("chnid=%d,name=%s,cps=%d\n",next.chnid,next.desc,next.cps);
	return 0;
}
#endif
