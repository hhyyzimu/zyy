#include <iostream>
using namespace std;

class stu
{
	public:
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
				cout<<"errno,return 0!"<<endl;
				}
			}
			int get_id()
			{
				return id;
				}
			string get_name()
			{
				return name;
				}
			int get_math()
			{
				return math;
				}
			void print()
			{
				cout<<"this="<<this<<endl;
				cout<<"id="<<id<<endl;
				cout<<"name="<<name<<endl;
				cout<<"math="<<math<<endl;
				}
	};

int main()
{
	stu stu1,stu2;
	stu1.set(1,"a",10);
	stu1.print();
	cout<<"&stu1="<<&stu1<<endl;
	stu2.set(2,"b",20);
	stu2.print();
	cout<<"&stu2="<<&stu2<<endl;
	return 0;
	}
