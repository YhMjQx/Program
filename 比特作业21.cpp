#include<stdio.h>
void print(int x)
{
	int i=0;
	printf("����λ��"); 
	for(i=30;i>=0;i-=2)
	{
		printf(" %d",(x>>i)&1);
	}
	printf("\n");
	printf("ż��λ��");
	for(i=31;i>=1;i-=2)
	{
		printf("%d ",(x>>i)&1);
	}
	printf("\n");
}
int main()

{
	int m=0;
	printf("������������ҵ�����"); 
	scanf("%d",&m);
	print(m);
	return 0;
	
}
