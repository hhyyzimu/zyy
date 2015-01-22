/*函数重载*/
#include <iostream>
using namespace std;

void add(int a,int b)
{
	int c;
	c=a+b;
	cout<<"c="<<c<<endl;
	}
void add(double a,double b)
{
	double c;
	c=a+b;
	cout<<"c="<<c<<endl;
	}
void add(int a,int b,int d)
{
	int c;
	c=a+b+d;
	cout<<"c="<<c<<endl;
	}

int main()
{
	int x=100;
	int y=200;
	double m=12.3;
	double n=12.4;
	add(x,y);
	add(m,n);
	add(x,y,300);

	return 0;
	}
