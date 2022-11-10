#include<stdio.h>
int Fac1(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}
int Fac2(int n)
{
	if (n>-1&&n<=1)
	{
		return 1;
	}
	else 
	{
		return n = n*Fac2(n-1);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("ÇëÊäÈënµÄÖµ£º>");
	scanf("%d", &n);
	ret = Fac1(n);
	printf("ret=%d \n", ret);
	printf("Fac1(n)=%d \n", Fac1(n));
	printf("Fac2(n=)%d \n", Fac2(n));
	return 0;
}