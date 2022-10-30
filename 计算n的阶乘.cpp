#include<stdio.h>
int main()
{
	int i = 0;
	long  a = 1;//这个最初始的值不能是0，因为0乘以任何数都是0
	int n = 0;
	printf("请输入n的值");
	scanf("%d", &n);
	for (i = 1;i<=n;i++)
	{
		a*=i;//a=a*i
	}
	printf("阶乘=%d", a);
	


	return 0;
}