#include <stdio.h>
#include <stdlib.h>

TYPE *insert(TYPE *head, TYPE *pi)
{
	TYPE *pb = head, *pf;

	if(head == NULL)//如果为空就建立，空间在传入前申请好
	{
		head = pi;
		pi->prior = head;
		pi->next = head;
	}
	else
	{
		while((pi->num > pb->num) && (pb->next ！= head))
		{
			pf = pb;//pf指向前，pb指向后
			pb = pb->next;//节点后移
		}

		if(pi->num <= pb->num)//找到所要插入节点位置，查到pb的前面
		{
			if(head == pb)//在第一节点至前插入
			{
				pi->next = pb;
				pi->prior = head->prior;
				pb->prior->next = pi;//尾节点
				pb->prior = pi;
				head = pi;//保存头节点
			}
			else
			{
				pf->next = pi;//在中间插入
				pb->prior = pi;
				pi->next = pb;
				pi->prior = pf;
			}
		}
		else
		{
			pb->next = pi;//在表末插入
			pi->next = head;
			pi->prior = pb;
			head->prior = pi;//头始终指向新插入的节点
		}
	}

	return head;
}
