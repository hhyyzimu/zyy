#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>

#define PATHSIZE 1024

static path_noloop(const char *path)
{
	char *pos;

	pos = strrchr(path,'/');//返回/后面的字符串的指针
	if(pos == NULL)
		exit(1);
	if(strcmp(pos+1,".")==0 || strcmp(pos+1,"..")==0)
		return 0;

	return 1;
	}
static int64_t mydu(const char *path)
{
	int i,err;
	int64_t sum = 0;
	glob_t globres;
	struct stat statres;
	char nextpath[PATHSIZE];

	if(lstat(path,&statres)<0)
	{
		perror("lstat()");
		exit(1);
		}
	if(!S_ISDIR(statres.st_mode))
		return statres.st_blocks;

	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/*",PATHSIZE);
	err = glob(nextpath,0,NULL,&globres);

	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/.*",PATHSIZE);
	err = glob(nextpath,GLOB_APPEND,NULL,&globres);

	sum = statres.st_blocks;
	for(i=0; i<globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);//如果不是/.或/..就sum+1，
		}
	return sum;
	}

int main(int argc,char **argv)
{
	if(argc < 2)
	{
		fprintf(stderr,"Usage...\n");
		}

	printf("%d\t%s\n",mydu(argv[1]) / 2,argv[1]);
	exit(0);
	}
