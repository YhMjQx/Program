#include<stdio.h>
int Pow(int n,int k)
{
	if(k==0)
	{
		return 1;
	}
	else if(k>=1)
	{
		return n*Pow(n,k-1);
	}
	else
	{
		return 1/(n*Pow(n,k+1));
	}
}
int main()
{
	int n=0;
	int k=0;
	int sum=1; 
	printf("����������Ҫ�������n�ʹη���k:>");
	scanf("%d %d",&n,&k);
	printf("%d",Pow(n,k));
	return 0;
 } 
