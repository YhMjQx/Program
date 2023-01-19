#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//int fputs(const char* string,FILE* stream)
	//将一个const char* string写进FILE* stream
	//也即是说将一个常量数据写进一个文件，但参数是指向这个文件的指针
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}


	//写文件
	fputs("YhMjQx\n", pf);
	//关闭文件
	fclose(pf);
	pf = NULL;
	return 0;
}