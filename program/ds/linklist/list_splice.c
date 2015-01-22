static inline void __list_splice(const struct list_head *list,
				struct list_head *prev,
				struct list_head *next)
{
	struct list_head *first = list->next;
	struct list_head *last = list->prev;

	first->prev = prev;
	prev->next = first;

	last->next = next;
	next->prev = last;
}

static inline void list_splice(const struct list_head *list,
				struct list_head *head)
{
	if(!list_empty(list))
		__list_splice(list, head, head->next);
}
