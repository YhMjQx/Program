#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	//strcat
	//源字符串必须以'\0'结束；目标空间必须足够大，能容纳下源字符串的内容；
	//目标空间必须可修改。
	char arr1[39] = "abcdef";
	char arr2[] = "ghijklmn";
	//strcat(arr1, arr2);
	//printf("%s\n", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}