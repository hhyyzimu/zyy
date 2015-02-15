swap(int *p1, int *p2)
{
	int *p; //p是一个野指针，有可能指向系统区，导致程序运行崩溃
	*p = *p1;
	*p1 = *p2;
	*p2 = *p;
}

//应改为
swap(int *p1, int *p2)
{
	int p;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
}
