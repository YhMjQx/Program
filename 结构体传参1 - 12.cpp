#include<stdio.h>
typedef struct S
{
	char* ch1;
	char* ch2;
	char* ch3;
	int a;
}stu;
void Init( stu* ps)
{
	ps->ch1 = "YMQ"; 
	ps->ch2 = "HJX";
	ps->ch3 = "YhMjQx";
	ps->a = 1314;
}
//这里的因为"YMQ""HJX""YhMjQx"写在代码内部相当于是常量，他的存储空间由静态区提供。而定义数组相当于是在栈区分配空间
//所以我在这如果将代码写作char ch1[39];ps->ch1="YMQ";这样的代码操作就是错误的
//有两种修改方法：
//1.不定义字符型数组，而是定义一个字符型指针，也就是让一个指针指向静态区的字符串
//2.不在代码内部写入"YMQ""HJX""YhMjQx"这样的代码，而是写一个scanf() / gets()从键盘上获取数据
void Print(const S* ps)
{
	printf("%s\n", ps->ch1);
	printf("%s\n", ps->ch2);
	printf("%s\n", ps->ch3);
	printf("%d\n", ps->a);
}
int main()
{
	S stu = { 0 };
	//printf("%s\n", s.ch1);
	//printf("%s\n", s.ch2);
	//printf("%s\n", s.ch3);
	//printf("%d\n", s.a);
	Init(&stu);//初始化要想改变结构体内部的的值应该传地址
	Print(&stu);
	return 0;
}