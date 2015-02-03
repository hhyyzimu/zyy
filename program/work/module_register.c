int module_register(struct module *parent, struct module *m)
{
	if(parent == NULL){
		list_add_tail(&m->list, &modules_head);
	} else {
		if(parent->children.next == NULL ||
				parent->children.prev == NULL){
			INIT_LIST_HEAD(&parent->children);
		}
		list_add_tail(&m->list, &parent->children);
	}
	INIT_LIST_HEAD(&m->children);
	return 0;
}
