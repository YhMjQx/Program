#include<stdio.h>
double Pow(int n,int k)
{
	
	if(k==0)
	{
		return 1;
	}
	else if(k<0)
	{
		return (1.0/(Pow(n,-k)));
	}
	else
		return n*Pow( n, k-1);
}
int main()
{
	int n=0;
	int k=0;
	printf("请输入想要计算的底数和指数：");
	scanf("%d %d",&n,&k);
	double ret=Pow(n,k);
	printf("ret=%lf",ret);
	return 0;
}
