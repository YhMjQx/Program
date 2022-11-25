#include<stdio.h>
int main()
{
int i=0;
int count=0; 
for(i=100;i<=200;i++)
{
	int j=0;
	for(j=2;j<=i-1;j++)
	{
		if(0==i%j)
		{
		break;//由于i此时能被一个2到i-1之间的数字整除，因此i不是素数，不打印，跳出这个循环 
		}
	}
	if(i==j)//既然此时i会被整除，那么就来验证一下这个i和j是不是相等的，如果是相等那就是素数，就打印 
	{
		printf("%d ",i);
		count++;
	 } 
}
printf("\n一共有%d个素数\n",count); 

	return 0;
	
} 
