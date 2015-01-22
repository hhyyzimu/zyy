list_entry(task->tasks.next, struct task_struct, tasks)

#define list_entry(ptr, type, member) \
		container_of(ptr, type, member)

#define container_of(ptr, type, member) ({
		const typeof(((type *)0)->member) *__mptr = (ptr);
		(type *)((char *)__mptr - offsetof(type, member));
})

/*
 *container_of: cast a member of a structure out to the containing structure;
 *ptr: the pointer to the member.
 *type: the type of the container struct this is embedded in.
 *member: the name of the member within the struct.
 *
 *const定义了一个制度变量*__mptr,他是一个指针.
 *type取参数的数据类型.
 *把list_entry的参数带到这里：((struct task_struct *)0->tasks)把struct task_struct的首地址虚拟为0x00000000,
 *
 *
 *
 *
 *
 *
 *
 * */
