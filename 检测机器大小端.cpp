#include<stdio.h>
/*void cheak_sys()
{
	int a = 1;
	char* p = (char*)&a;
	if (*p == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
}*/
/*int cheak_sys()
{
	int a = 1;
	char* p = (char*)&a;
	return *p;
}*/
int cheak_sys()
{
	int a = 1;
	return *(char*)&a;
}//指针类型有两个 1.指针类型决定了解引用操作符能访问几个字节，char*能访问1个字节，int*能访问4个字节
 // 2.指针类型决定了指针+1或者-1时，加减的到底是几个字节，char* p，p+1跳过一个字节，int* p，p+1跳过4个字节
int main()
{
	int a = 1;
	int ret=cheak_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;

}