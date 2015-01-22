/*函数参数默认值*/
#include <iostream>
using namespace std;

void print(int a=100,int b=200)
{
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	}
void print1(int a,int b,int c=100,int d=200)
{
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
	cout<<"d="<<d<<endl;
	}

int main()
{
	print();
	print(600);
	print(600,700);
	//print1();
	print1(1,2);
	print1(1,2,3);
	return 0;
	}
