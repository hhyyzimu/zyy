void GetMemory(char *p)
{
	p = (char *)malloc(100); //在函数内部修改形参并不能真正的改变传入形参的值
}

void Test(void)
{
	char *str = NULL;
	GetMemory(str); //str仍为NULL
	strcpy(str, "hello world");
	printf(str);
}
