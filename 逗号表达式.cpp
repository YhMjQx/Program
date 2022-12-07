#include<stdio.h>
int main()
{
	//逗号表达式，从左向右依次计算，最后一个逗号表达式的结果，为整个逗号表达式的结果 
	int a=1;
	int b=2;
	int c=(a>b,a=b+10,a,b=a+1);
	printf("%d\n",c);
	return 0;
 } 
