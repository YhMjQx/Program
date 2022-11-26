#include<stdio.h>
int Leapyear(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	{
		return 1;
	}
	else
	return 0;
}
int main()
{
	int year=0;
	printf("请输入想判断的年份:>");
	scanf("%d",&year);
	if(Leapyear(year)==1)
	{
		printf("%d年是闰年",year); 
	}
	else
	{
		printf("%d不是闰年",year); 
	} 
	return 0;
}
