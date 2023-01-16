#include<stdio.h>
char* Getmemory()
{
	char p[] = "YhMjQx";
	return p;
}
//返回栈空间的地址的问题
//当程序走出代码的时候，p指向的这一片空间已经销毁了，已经返回给了操作系统，现在的p是一个没有指向任何空间的指针变量
//于是，现在将p赋给str再打印的话，str根本找不到对应的空间，所以打印出来的就是乱码
void test()
{
	char* str = NULL;//一般情况下要把str初始化为NULL，防止野指针问题，因为野指针的解引用有可能造成非法访问
	str = Getmemory();
	printf(str);
}
int main()
{
	test();
	return 0;
}