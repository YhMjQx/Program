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
int Fact2(int n)//����������n�����ҵ�Ȼ��Ҫ����n�Ľ׳��� 
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
	printf("����������Ҫ����Ľ׳˽���:>");
	scanf("%d",&n);
	printf("Fact1���Ϊ%d\n",Fact1(n));
	printf("Fact2���Ϊ%d\n",Fact2(n));
}
