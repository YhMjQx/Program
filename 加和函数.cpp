#include<stdio.h>
int Add(int x, int y)//定义一个加和函数，简化下面的代码(自定义函数-自己设计）
{//注意，自定义函数也是需要使用大括号括起来的
	int z = x + y;
	return z;
}
int main()//（类似于printf和scanf都是库函数）
{
	int sum;
	int num1 = 10;
	int num2 = 20;
	sum=Add(num1,num2);
	printf("%d\n", sum);
	int a = 100;
	int b = 200;
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}