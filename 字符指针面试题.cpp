#include<stdio.h>
int main()
{
	char arr1[] = "YhMjQx";
	char arr2[] = "YhMjQx";
	char* p1 = "YhMjQx";
	char* p2 = "YhMjQx";
	if (arr1 == arr2)
	{
		printf("haha\n");
	}
	else
	{
		printf("hehe\n");//结果在此，arr1和arr2是两个不同的数组，创建的是两个不同的地址
	}
	if (p1 == p2)
	{
		printf("haha\n");//结果在此，YhMjQx是相同的，对于p1，p2在内存中来说，YhMjQx只存一份，p1，p2的地址是一样的，都是YhMjQx的首地址
	}
	else
	{
		printf("hehe\n");
	}
	return 0;
}