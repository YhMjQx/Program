#include<stdio.h>
int main()
{
	int a; 
	printf("������a��ֵ���ڲ鿴�Լ��ĵȼ�\n");
	scanf("%d",&a);
	if(a>=100||a<0) 
	printf("������ķ�������");
	else if(a<=99&&a>=90)
	{
	printf("A");
	}
	else if(a<=89&&a>=80)
	{
	printf("B");
	}
	else if(a<=79&&a>=70)
	{
	printf("C");
	}
	else if(a<=69&&a>=60)
	{
	printf("D");
	}
	else
	{
	printf("E");
	}
	return 0;
}
	
