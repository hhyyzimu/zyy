#include <iostream>
using namespace std;

class stu
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
				cout<<"errorn,return 0!"<<endl;
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
			cout<<"id="<<id<<endl;
			cout<<"name="<<name<<endl;
			cout<<"math="<<math<<endl;
			}
	};

	int main()
	{
		stu stu1;
		stu1.set(100,"a",30);
		stu1.print();
		int id_main;
		id_main=stu1.get_id();
		cout<<"id_main="<<id_main<<endl;

		return 0;
		}
