#include<stdio.h>
int main()
{
	int a = 10;//一个整型，4byte，32bit
	int* p = &a;//p（指针）其类型为int*，有一种变量用来存放地址的--指针变量
	printf("&a=%p\n", &a);
	printf("p=%p\n", p);
	*p = 20;//*（在这里的作用是解引用，即解开p的取地址，将取到的地址丢掉，并将该地址的内容由10换成20，实际上也就是a变成了20）
	        //这里的*p就相当于a
	printf("a=%d\n", a);
	return 0;
}