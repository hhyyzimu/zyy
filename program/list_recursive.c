LINK_NODE *ReverseLink2(LINK_NODE *head)
{
	LINK_NODE *newHead;

	if((head == NULL || (head->next == NULL)))
		return head;

	newHead = ReverseLink2(head->next);
	head->next->next = head;
	head->next = NULL;

	return newHead;
}
