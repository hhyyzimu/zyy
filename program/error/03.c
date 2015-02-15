void GetMemory(char **p, int num)
{
	*p = (char *)malloc(num); //未判断是否申请地址成功,未对malloc进行释放，也未避免野指针
}

void Test(void)
{
	char *str = NULL;
	GetMemory(&str, 100);
	strcpy(str, "hello");
	printf(str);
}
