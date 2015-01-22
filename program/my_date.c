#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define TIMESTRSIZE	1024
#define FMTSIZE	1024

int main(int argc,char *argv[])
{
	FILE *fp = stdout;
	time_t stamp;
	struct tm *tm;
	char timestr[TIMESTRSIZE];
	int ch;
	char fmt[FMTSIZE] = {'\0'};


	stamp = time(NULL);
	tm = localtime(&stamp);


	while(1)
	{
		ch = getopt(argc,argv,"-y:mdH:MS");
		if(ch < 0)
			break;

		switch(ch)
		{
			case 1:
				if(fp == stdout)
				{
					fp = fopen(argv[optind-1],"w");	
					if(fp == NULL)
					{
						perror("fopen()");
						fp = stdout;//因为接下来会有内容输出到文件描述符，所以必须给文件描述符指定到一个地方
						break;
					}
				}
				break;
			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmt,"%y ",FMTSIZE);
				else if(strcmp(optarg,"4") == 0)
						strncat(fmt,"%Y ",FMTSIZE);
					 else 
						fprintf(stderr,"Invalid argument of -y\n");
				break;
			case 'm':
				strncat(fmt,"%m ",FMTSIZE);
				break;
			case 'd':
				strncat(fmt,"%d ",FMTSIZE);
				break;
			case 'H':
				if(strcmp(optarg,"12") == 0)
                    strncat(fmt,"%I(%P) ",FMTSIZE);
                else if(strcmp(optarg,"24") == 0)
                        strncat(fmt,"%H ",FMTSIZE);
                     else
                        fprintf(stderr,"Invalid argument of -H\n");

				break;
			case 'M':
				strncat(fmt,"%M ",FMTSIZE);
				break;
			case 'S':
				strncat(fmt,"%S ",FMTSIZE);
				break;
			default:
				/*do sth*/
				break;
		}

	}

	strncat(fmt,"\n",FMTSIZE);
	strftime(timestr,TIMESTRSIZE,fmt,tm);
	fputs(timestr,fp);//需要输出到文件流中，所以fp必须指定一个已经打开文件描述符

	if(fp != stdout)
		fclose(fp);

	exit(0);
}
