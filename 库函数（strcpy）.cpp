#include<stdio.h>
#include<string.h>
int main()
{
	//strcpy - string copy - 字符串拷贝
	//strlen - string length - 求字符串长度#include<string.h>
	char arr1[] = { "杨明强\n" };
	char arr2[] = { "谁爱胡佳欣" };
	strcpy(arr2, arr1);//将后者的字符串拷贝后覆盖到前者中
	printf("%s", arr2);
	return 0;
}