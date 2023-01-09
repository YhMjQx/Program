#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[39] = "YMQ love ";
	char arr2[] = "HJX";
	strncat(arr1, arr2, 3);
	printf("%s\n", arr1);
	//这个函数是不受字符串长度限制的字符串函数，我所给的字节数可以大于源字符串的长度
	//该函数每次追加完后都会自动补'\0'，就算要求的字节数大于自身的长度，我也只补一个'\0'
	return 0;
}