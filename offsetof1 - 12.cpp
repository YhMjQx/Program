#include<stdio.h>
#include<stddef.h>
struct Y
{
	char a;
	int b;
	double c;
};
//size_t offsetof(structName ,memberName)这是一个宏，可以传类型
int main()
{
	//offsetof();计算结构体成员变量相对于结构体起始位置的偏移量是多少
	printf("%d\n", offsetof(struct Y, a));
	printf("%d\n", offsetof(struct Y, b));
	printf("%d\n", offsetof(struct Y, c));
	return 0;
}