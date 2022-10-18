#include<stdio.h>
int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;//C语言规定变量都定义在最前端
	scanf("%d%d", &num1, &num2);//输入函数scanf，取地址符号&
	sum = num1 + num2;
	printf("sum=%d\n", sum);
	return 0;
}
