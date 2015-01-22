#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

static jmp_buf save;

void d(void)
{
	printf("%s():Begin!\n", __func__);
	printf("%s():Jump now!\n", __func__);
	longjmp(save, 0);//默认将0改为1，跳到a函数
	printf("%s():End!\n", __func__);
}

void c(void)
{
	printf("%s():Begin!\n", __func__);
	printf("%s():Call d()!\n", __func__);
	d();
	printf("%s():d() returned!\n", __func__);
	printf("%s():End!\n", __func__);
}

void b(void)
{
	printf("%s():Begin!\n", __func__);
	printf("%s():Call c()\n", __func__);
	c();
	printf("%s():c() returned!\n", __func__);
	printf("%s():End!\n", __func__);
}

void a(void)
{
	int ret;

	printf("%s():Begin!\n", __func__);

	ret = setjmp(save);
	if(ret == 0)//跳转成功
	{
		printf("%s():Call b()!\n", __func__);
		b();
		printf("%s():b() returned!\n", __func__);
	}
	else//返回值
	{
		printf("%s():Jumped back here with code %d!\n", __func__, ret);
	}
	printf("%s():End!\n", __func__);
}

int main()
{
	printf("%s():Begin!\n", __func__);
	printf("%s():Call a()!\n", __func__);
	a();
	printf("%s():a() returned!\n", __func__);
	printf("%s():End!\n", __func__);

	exit(0);
}
