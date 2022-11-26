#include<stdio.h>
void Cfb(int n)
{
	int i=0;
	for(i=1;i<=n;i++)
	{
		int j=0;
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-2d\t",i,j,i*j);
		}
		printf("\n");
	}
}
int main()
{
    int n=0;
	printf("请输入您想要的乘法表阶数n:>");
	scanf("%d",&n);
	Cfb(n);
	return 0;
}
