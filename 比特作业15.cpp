#include<stdio.h>
//���⴮���ַֿ���ӡ 
int  Snum(int num)
{
	if(num>9)
	{
		Snum(num/10); 
	}
	return printf("%d ",num%10);
}
//���⴮���ּ����� 
int DigitSum(int num)
{
	if(num>9)
	{ 
	if(num>9)
		return DigitSum(num/10)+num%10;
	else
		return num;
	}
}
int main()
{
	int num=0;
	printf("������һ������:>");
	scanf("%d",&num);
	Snum(num);
	printf("\n");
	printf("�⴮���ֵĺ�=%d",DigitSum(num));
	return 0;
 } 
