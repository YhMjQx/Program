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
	printf("���������жϵ����:>");
	scanf("%d",&year);
	if(Leapyear(year)==1)
	{
		printf("%d��������",year); 
	}
	else
	{
		printf("%d��������",year); 
	} 
	return 0;
}
