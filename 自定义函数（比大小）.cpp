#include<stdio.h>
int MAX(int x, int y)
{
	int  exp(x > y ? x : y);
	return exp;
	/*if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
	这也是一种方法，不过三目操作符更加简洁
*/
}
int main()
{
	int a = 10;
	int b = 20;
	int max= MAX(a,b);
	printf("%d ", max);
	return 0;
}