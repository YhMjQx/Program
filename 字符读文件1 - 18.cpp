#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE* pfRead = fopen("TEXT.txt", " r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	} 
	//读文件
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	//关闭文件
	fclose(pfRead);
	pfRead = NULL;
	return 0;
}