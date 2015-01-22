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

stu *create()
{
	stu *head = NULL;
	stu *p = NULL;
	stu *new = NULL;
	int iid = 0;
	char iname[20] = "";
	int imath = 0;

	head = malloc(sizeof(stu));
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		iid++;
		printf("please input name:");
		scanf("%s", iname);
		printf("please input math:");
		scanf("%d", &imath);
		head->id = iid;
		strcpy(head->name, iname);
		head->math = imath;
		head->next = NULL;
		p = head;

		while(1)
		{
			iid++;
			printf("please input name, the 0 is interrupt:");
			scanf("%s", iname);
			if(iname[0] == '0')
			{
				break;
			}
			printf("please input math:");
			scanf("%d", &imath);
			new = malloc(sizeof(stu));
			new->id = iid;
			strcpy(new->name, iname);
			new->math = imath;
			new->next = NULL;
			p->next = new;
			p = new;
		}
	}
	return head;
}

void print(stu *head)
{
	stu *p = head;
	while(p != NULL)
	{
		printf("id = %d\n", p->id);
		printf("name = %s\n", p->name);
		printf("math = %d\n", p->math);
		p = p->next;
	}
}

int main()
{
	stu *h = create();
	print(h);

	exit(0);
}
