#include<stdio.h>
int main()
{
	int i = 0;
	long  a = 1;//要用来乘的数可不能是0
	int n = 0;
	int b = 0;
	int sum = 0;
	printf("请输入b的值");
	scanf("%d", &b);
	for (n = 1; n <= b; n++)
	{
			a = a*n;
		sum = sum + a;
	}
	printf("sum=%d", sum);
	return 0;
}