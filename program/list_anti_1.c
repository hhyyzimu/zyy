#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

//创建链表
Node *CreatList(void)
{
	int i;
	Node *head, *p, *q;
	head = NULL;

	printf("请输入您要输入的数据：\n");
	scanf("%d", &i);
	while(i != 0)
	{
		p = (Node *)malloc(sizeof(Node));
		p->data = i;
		if(head == NULL)
			q = head = p;
		else
			q->next = p;
		q = p;
		scanf("%d", &i);
	}
	p->next = NULL;
	return head;
}

//链表逆置
Node *ReverseList(Node *head)
{
	Node *p, *q, *r;

	p = head;
	q = r = NULL;
	while(p)
	{
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}

	return r;
}

//输出链表
void PrintList(Node *head)
{
	Node *p;
	p = head;
	while(p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

int main(void)
{
	Node *head;
	
	head = CreatList();
	printf("链表逆置前的数据：\n");
	PrintList(head);

	head = ReverseList(head);
	printf("链表逆置后的数据：\n");
	PrintList(head);

	return 0;
}
