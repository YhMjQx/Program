#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = "abcdefabcdef";
	const char arr2[] = "bcde";
	char* ret = strstr(arr1, arr2);
	//char* strstr(char* ,const char*),返回的是一个指针，类似于这个题目，返回的是abcdefabcdef当中的第一个b的地址
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}