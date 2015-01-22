/*图形*/
#include <iostream>
using namespace std;

class tx
{
	protected:
		double a;
		double b;
		double l;
		double s;
	public:
		tx(double a1=0,double b1=3.14)
		{
			if(a1>=0 && b1>=0)
			{
				a=a1;
				b=b1;
				}
			else
			{
				a=0;
				b=3.14;
				cout<<"图形构造"<<endl;
				}
		}
		virtual ~tx()
		{
			cout<<"tx析构函数"<<endl;
			}
		void set(double a1=0,double b1=3.14)
		{
			if(a1>=0 && b1>=0)
			{
				a=a1;
				b=b1;
				}
			else
			{
				a=0;
				b=3.14;
				cout<<"数据输入错误，数据回0"<<endl;
				}
			}
		double get_a()
		{
			return a;
			}
		double get_b()
		{
			return b;
			}
		double get_l()
		{
			return l;
			}
		double get_s()
		{
			return s;
			}
		void print()
		{
			cout<<"l="<<l<<endl;
			cout<<"s="<<s<<endl;
			}
		virtual void js()=0;
		virtual void A(int x=100)
		{
			cout<<"x="<<x<<endl;
			cout<<"tx 类 A函数"<<endl;
			}
	};
class yuan:public tx
{
	public:
		yuan(double a1=0):tx(a1)
		{
			cout<<"yuan构造"<<endl;
			}
		virtual ~yuan()
		{
			cout<<"yuan析构"<<endl;
			}
		void set(double a1=0)
		{
			tx::set(a1);
			}
		void js()
		{
			l=2*b*a;
			s=b*a*a;
			cout<<"yuan js()函数"<<endl;
			}
		virtual void A(int x=200)
		{
			cout<<"x="<<x<<endl;
			cout<<"yuan 类 A函数"<<endl;
			}
	};
class cfx:public tx
{
	public:
		cfx(double a1=0,double b1=0):tx(a1,b1)
		{
			cout<<"cfx构造"<<endl;
			}
		virtual ~cfx()
		{
			cout<<"cfx析构"<<endl;
			}
		void set(double a1=0,double b1=0)
		{
			tx::set(a1,b1);
			}
		virtual void js()
		{
			l=(a+b)*2;
			s=a*b;
			cout<<"cfx js()函数"<<endl;
			}
	};
int main()
{
	tx *p=NULL;
	p=new yuan;
	delete p;
	p=NULL;
	p=new cfx;
	delete p;
	}
