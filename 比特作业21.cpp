#include<stdio.h>
void print(int x)
{
	int i=0;
	printf("奇数位："); 
	for(i=30;i>=0;i-=2)
	{
		printf(" %d",(x>>i)&1);
	}
	printf("\n");
	printf("偶数位：");
	for(i=31;i>=1;i-=2)
	{
		printf("%d ",(x>>i)&1);
	}
	printf("\n");
}
int main()

{
	int m=0;
	printf("请输入你想查找的数："); 
	scanf("%d",&m);
	print(m);
	return 0;
	
}
