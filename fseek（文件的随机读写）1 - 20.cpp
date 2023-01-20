#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//int fseek(FILE* stream,long int offset,int origin)
	//FILE* stream - pf
	//long int offset - 偏移量
	//int origin - 文件指针当前位置
	//SEEK_CUR - 文件指针的当前位置
	//SEEK_SET - 文件的起始位置
	//SEEK_END - 文件的末尾位置
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//定位文件指针
	fseek(pf, 2, SEEK_CUR);
	char ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}