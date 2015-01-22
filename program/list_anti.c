LINK_MODE *ReverseLink(LINK_NODE *head)
{
	LINK_NODE *next;
	LINK_NODE *prev = NULL;

	while(head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return prev;
}
