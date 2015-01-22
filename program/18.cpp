#include <iostream>
using namespace std;

class stu
{
	public:
		int id;
		string name;
		int math;
	public:
		stu(int id1,string name1,int math1)
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
				cout<<"errno!"<<endl;
				}
			cout<<"this="<<this<<endl;
			cout<<"有参构造函数"<<endl;
			}
		stu()
		{
			id=0;
			name="";
			math=0;
			cout<<"无参构造函数"<<endl;
			}
		~stu()
		{
			cout<<"this="<<this<<endl;
			cout<<"析构函数"<<endl;
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
		stu *px=NULL;
		px=new stu[3];//对象数组调用无参构造函数
		px[0].print();
		px[1].print();
		px[2].print();
		delete []px;
		stu *pa=NULL;
		pa=new stu(100,"a",90);
		pa->print();
		delete pa;
		return 0;

		}
