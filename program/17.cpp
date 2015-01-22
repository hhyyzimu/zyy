/*动态创建和释放对象*/
#include <iostream>
using namespace std;

int main()
{
	int *p=NULL;
	char *pc=NULL;
	double *pd=NULL;
	int *px=NULL;
	p=new int;
	pc=new char;
	pd=new double;
	px=new int[10];
	*p=100;
	*pc='x';
	*pd=12.3;
	cout<<"*p="<<*p<<endl;
	cout<<"*pc="<<*pc<<endl;
	cout<<"*pd="<<*pd<<endl;
	int i=0;
	for(i=0;i<10;i++)
	{
		px[i]=i+100;
		}
	for(i=0;i<10;i++)
	{
		cout<<"px["<<i<<"]="<<px[i]<<endl;
		}
	delete p;
	delete pc;
	delete pd;
	delete []px;

	return 0;
	}
