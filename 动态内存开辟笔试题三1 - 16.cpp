#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Getmemory(char** p,int num)
{
	*p = (char*)malloc(num);
}//����mallocȴû��free�������ڴ�й©
void test()
{
	char* str = NULL;
	Getmemory(&str, 100);
	char p[] = "YhMjQx";
	strcpy(str, p); 
	printf(str);
	free(str);//ע��ע�⣬һ��Ҫ��free����
	str = NULL;
}
int main()
{
	test();
	return 0;
}