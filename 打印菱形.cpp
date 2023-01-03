#include<stdio.h>
int main()
{
	int line = 0;
	printf("请输入想要的菱形的上半部分的行数:>\n");
	scanf("%d", &line);
	int i = 0;
	//打印上半部分
	for (i = 0; i < line; i++)
	{
		//打印空格
		int j = 0;
		for (j = 0; j < line -1- i; j++)
		{
			printf(" ");
		}
		//打印 *
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	//打印下半部分
	for (i = 0; i < line - 1; i++)
	{
		//打印空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}