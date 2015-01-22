/*传递动态内存*/
#include <iostream>
#include <stdlib.h>
//using namespace std;

void getmemory(char **p,int num)
{
	*p=(char *)malloc(sizeof(char)*num);
	};
int main()
{
	char *str=NULL;
	getmemory(str,100);
	strcpy(str,"hello");
	cout<<*str<<endl;
	cout<<str<<endl;
	cout<<&str<<endl;

	return 0;
	}

