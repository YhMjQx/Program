#include<stdio.h>
int main()
{
	char arr[10] = "YhMjQx";
	char* p = arr;
	printf("%s\n", arr);
	printf("%s\n", p);
	char* pc = "YhMjQx";//这是一个常量字符串，利用指针不能对其进行修改
	printf("%s\n", pc);
	return 0;
}
