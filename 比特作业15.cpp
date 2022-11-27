#include<stdio.h>
//将这串数字分开打印 
int  Snum(int num)
{
	if(num>9)
	{
		Snum(num/10); 
	}
	return printf("%d ",num%10);
}
//将这串数字加起来 
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
	printf("请输入一串数字:>");
	scanf("%d",&num);
	Snum(num);
	printf("\n");
	printf("这串数字的和=%d",DigitSum(num));
	return 0;
 } 
