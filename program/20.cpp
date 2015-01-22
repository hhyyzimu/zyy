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
				cout<<"errno and return 0!"<<endl;
				}
			}
		~tx()
		{
			cout<<"析构函数"<<endl;
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
				cout<<"errno and return 0!"<<endl;
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
		void js()
		{
			
			}
	};
class yuan:public tx
{
	public:
		yuan(double a1=0):tx(a1)
		{
			
			}
		~yuan()
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
			}
	};
class cfx:public tx
{
	public:
		cfx(double a1=0,double b1=0):tx(a1,b1)
		{
			
			}
		~cfx()
		{
			cout<<"cfx析构"<<endl;
			}
		void set(double a1=0,double b1=0)
		{
			tx::set(a1,b1);
			}
		void js()
		{
			l=(a+b)*2;
			s=a*b;
			}
	};

int main()
{
	yuan y1(100);
	y1.js();
	y1.print();
	cfx c1(100,200);
	c1.js();
	c1.print();
	yuan y2;
	y2.js();
	y2.print();
	cfx c2;
	c2.js();
	c2.print();
	return 0;
	}
