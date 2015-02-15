char *GetMemory(void)
{
	char p[] = "hello world"; //p为局部变量，在函数返回后，内存已被释放
	return p;
}

void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}
