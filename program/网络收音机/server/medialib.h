#ifndef MEDIALIB_1_H__
#define MEDIALIB_1_H__

struct mlib_chn_st
{
	chnid_t chnid;
	int cps;
	char *desc;
};

int mlib_add_channel(char *pathname,int cps);
/**
 *-EINVAL     ,失败,目录没有，或读取目录失败
 *-ENOMEM     ,失败,无内存
 *-ENOSPC     ,失败,数组已满
 *>0          ,成功，返回频道号
 *
 * */
int mlib_off_channel(int id);
/*
 *-EINVAL     ,失败，id < 0
 *-ESRCH      ,失败，频道不存在
 *-ECANCELED  ,失败，早已经取消
 *0           ,成功
 * */

int mlib_wait_channel(int id);
/*
 *-EINVAL    ,失败，id < 0
 *0          ,成功
 *
 * */

int mlib_getchnlist(struct mlib_chn_st **,int *);
/**
 *	-ESRCH  ,失败，频道数为空
 *	0       ,成功，得到节目列表 
 * */

int mlib_delchnlist(struct mlib_chn_st *chnlist);
/*销毁节目列表*/

int mlib_getchndata(struct mlib_chn_st *chnl);
/*
 *-EINVAL    ,失败，参数为空,或者频道不存在
 *0          ,成功
 * */

#endif
