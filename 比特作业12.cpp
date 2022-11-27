#include<stdio.h>
int Fact1(int n)
{
	int i=0;
	int ret=1; 
	for(i=1;i<=n;i++)
	{
		ret*=i;
	}
	return ret;
}
int Fact2(int n)//传进来的是n啊，我当然是要计算n的阶乘了 
{
	if(n>-1&&n<=1)
	{
		return 1;
	}
	else
	{
	    n=n*Fact2(n-1); 
	}
	return n;
}
int main()
{
	int n=0;
	printf("请输入您想要计算的阶乘阶数:>");
	scanf("%d",&n);
	printf("Fact1结果为%d\n",Fact1(n));
	printf("Fact2结果为%d\n",Fact2(n));
}
