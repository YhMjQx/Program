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
		printf("hehe\n");//����ڴˣ�arr1��arr2��������ͬ�����飬��������������ͬ�ĵ�ַ
	}
	if (p1 == p2)
	{
		printf("haha\n");//����ڴˣ�YhMjQx����ͬ�ģ�����p1��p2���ڴ�����˵��YhMjQxֻ��һ�ݣ�p1��p2�ĵ�ַ��һ���ģ�����YhMjQx���׵�ַ
	}
	else
	{
		printf("hehe\n");
	}
	return 0;
}