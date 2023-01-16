#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Getmemory(char** p,int num)
{
	*p = (char*)malloc(num);
}//有了malloc却没有free，存在内存泄漏
void test()
{
	char* str = NULL;
	Getmemory(&str, 100);
	char p[] = "YhMjQx";
	strcpy(str, p); 
	printf(str);
	free(str);//注意注意，一定要让free存在
	str = NULL;
}
int main()
{
	test();
	return 0;
}