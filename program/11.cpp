#include <iostream>
using namespace std;

struct stu
{
	int id;
	string name;
	int math;
	};
class student
{
	private:
	int id;
	string name;
	int math;
	public:
	void set(int id1,string name1,int math1)
	{
		id=id1;
		name=name1;
		if(math1>=0)
		{
			math=math1;
			}
		else
		{
			math=0;
			cout<<"error!"<<endl;
			}
		}
	void print()
	{
		cout<<"id="<<id<<endl;
		cout<<"name="<<name<<endl;
		cout<<"math="<<math<<endl;
		}
	};

	int main()
	{
		struct stu stu1;
		stu1.id=101;
		stu1.name="zhangsan";
		stu1.math=-90;
		cout<<"stu1.id="<<stu1.id<<endl;
		cout<<"stu1.name="<<stu1.name<<endl;
		cout<<"stu1.math="<<stu1.math<<endl;
		student stu2;
		stu2.set(102,"lisi",20);
		stu2.print();
		return 0;
		}
