#include<stdio.h>
int MAX(int x, int y)//注意MAX，它也需要用int来定义 
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int max = 0;
	max = MAX(num1, num2);
	printf("较大值为%d\n", max);
	return 0;
}
//函数具有外部链接属性，该属性可以被static修饰进行改变 
