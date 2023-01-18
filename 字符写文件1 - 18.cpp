#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE* pfWrite = fopen("TEXT.txt", " w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//写文件
	fputc('Y', pfWrite);
	fputc('h', pfWrite);
	fputc('M', pfWrite);
	fputc('j', pfWrite);
	fputc('Q', pfWrite);
	fputc('x', pfWrite);
	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}