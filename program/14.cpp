#include <iostream>
using namespace std;

class A
{
	private:
		int x;
	public:
		A()
		{
			x=0;
			}
		A(int x1)
		{
			x=x1;
			}
		int get_x()
		{
			return x;
			}
	};
int main()
{
	A a;
	A b(10);
	cout<<"a.x="<<a.get_x()<<endl;
	cout<<"b.x="<<b.get_x()<<endl;
	return 0;
	}
