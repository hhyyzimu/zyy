/*popen*/
#include <stdio.h>
#include <stdlib.h>

#define _LINE_LENGTH 300

int get_path_total(const char *path, long long* total)
{
	int err = -1;
	FILE *file;
	char line[_LINE_LENGTH];
	char *p;
	char tmp[100];
	char *token;
	sprintf(tmp,"df %s",path);
	file = popen(tmp, "r");
	if(file != NULL)
	{
		if(fgets(file,_LINE_LENGTH,file) != NULL)
		{
			token = strtok(line," ");
			if(token != NULL)
			{
				
			}
			token = strtok(NULL," ");
			if(token != NULL)
			{
				*total = atoll(token)/1024;
				err = 0;
			}
		}
	}
	pclose(file);
	return err;
}

int main()
{
	

	exit(0);
}
