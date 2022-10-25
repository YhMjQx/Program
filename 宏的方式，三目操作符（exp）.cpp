#include<stdio.h>
#define MAX(x,y) (x>y?x:y)//用宏的定义法和三目操作符可以避免使用函数，因为函数比较麻烦 
int main()
{
	int x=10;
	int y=20;
	int max=MAX(x,y);
	printf("max=%d",max);
	return 0;
 } 
