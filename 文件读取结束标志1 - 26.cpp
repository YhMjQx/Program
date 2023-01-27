#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		//perror("自己添加");作用和strerror一样，用法更简单，用完后会在自己添加的内容后面加上冒号和一个空格
		return 0;
	}
	char ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		//fputc(ch,pf);
		putchar(ch);
	}
	printf("\n");
	if (ferror(pf))
	{
		printf("error of file!");
	}
	else if (feof(pf))
	{
		printf("end of file!");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
//feof应用于当文件读取结束的时候，判断是否是因为遇到了文件末尾的EOF而结束
//1.文本文件读取是否结束，判断返回值是否为EOF（fgetc），或者NULL（fgets）
//例如：fgetc用来判断是否为EOF，fgets用来判断是否为NULL
//2.二进制文件的读取结束判断，判断返回值是否小于实际要读的个数
//例如：fread判断返回值是否小于实际要读的个数