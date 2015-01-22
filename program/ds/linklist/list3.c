/*有头循环单链表*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
	int id;
	char name[20];
	int math;
	struct student *next;
}stu;
stu* create()
{
	stu *head=NULL;
	stu *p=NULL;
	stu *new=NULL;
	int iid=0;
	char iname[20]="";
	int imath=0;
	head=malloc(sizeof(stu));
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		head->id=0;
		strcpy(head->name,"");
		head->math=0;
		head->next=head;
		p=head;
		while(1)
		{
			iid++;	
			printf("输入姓名,输0退出:");
			scanf("%s",iname);
			if(iname[0]=='0')
			{
				break;
			}
			printf("输入成绩:");
			scanf("%d",&imath);
			new=malloc(sizeof(stu));
			new->id=iid;
			strcpy(new->name,iname);
			new->math=imath;
			new->next=head;
			p->next=new;
			p=new;
		}
	}
	return head;

}
void print(stu *head)
{
	stu *p=head->next;
	while(p!=head)
	{
		printf("id=%d\n",p->id);
		printf("name=%s\n",p->name);
		printf("math=%d\n",p->math);
		p=p->next;
	}
}
int select1(stu *head,char *sname)
{
	stu *p=head->next;
	while(p!=head)
	{
		if(!(strcmp(p->name,sname)))
		{
			printf("id=%d\n",p->id);
			printf("name=%s\n",p->name);
			printf("math=%d\n",p->math);
			return 1;
		}
		p=p->next;
	}
	return 0;
}
int insert1(stu *head,char *sname,int iid,char *iname,int imath)
{
	stu *p=NULL;
	stu *new=NULL;
	p=head->next;
	while(p!=head)
	{
		if(!(strcmp(p->name,sname)))
		{
			new=malloc(sizeof(stu));
			new->id=iid;
			strcpy(new->name,iname);
			new->math=imath;
			new->next=p->next;
			p->next=new;
			return 1;
		}
		p=p->next;
	}
	return 0;
}
int delete1(stu *head,char *dname)
{
	stu *p=NULL;
	stu *back=NULL;
	p=head;
	while(1)
	{
		back=p;
		p=p->next;
		if(!(strcmp(p->name,dname)))
		{
			back->next=p->next;
			free(p);
			return 1;
		}
		if(p!=head && p->next==head)
		{
			break;
		}
	}
	return 0;
}
void destroy1(stu *head)
{
	stu *p=NULL;
	stu *ph=head->next;
	while(ph!=head)
	{
		p=ph;
		ph=ph->next;
		printf("p->name=%s\n",p->name);
		free(p);
	}
	free(head);
	

}
int main()
{
	stu *h=create();
	destroy1(h);
/*	int a=0;
	char dname[20]="";
	stu *h=create();
	printf("输入删除人姓名:");
	scanf("%s",dname);
	a=delete1(h,dname);
	if(a==0)
	{
		printf("删除失败\n");
	}
	print(h);
	int a;
	int iid=0;
	char iname[20]="";
	int imath=0;
	char sname[20]="";
	stu *h=create();
	printf("输入查找人姓名:");
	scanf("%s",sname);
	printf("输入新增人学号:");
	scanf("%d",&iid);
	printf("输入新增人姓名:");
	scanf("%s",&iname);
	printf("输入新增人成绩:");
	scanf("%d",&imath);
	a=insert1(h,sname,iid,iname,imath);
	if(a==0)
	{
		printf("新增失败\n");
	}
	print(h);
	int a=0;

	char sname[20];

	printf("输入查找人姓名:");
	scanf("%s",sname);
	a=select1(h,sname);
	if(a==0)
	{
		printf("查无此人\n");
	}*/
//	print(h);
	return 0;
}
