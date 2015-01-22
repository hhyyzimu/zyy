#include <stdio.h>
#include <assert.h>

int main(void)
{
	FILE *fp;

	fp = fopen("test.txt", "w");
	assert(fp);
	fclose(fp);

	fp = fopen("noexitfile.txt", "r");
	assert(fp);
	fclose(fp);//如果文件不存在，程序不会执行到这里

	return 0;
}
