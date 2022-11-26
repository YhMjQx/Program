#include<stdio.h>
int main()
{
	int arr[10];
	int MAX=0;
	int i=0;
	for(i=1;i<=10;i++)
	{
		printf("请输入数字:>");
		scanf("%d",&arr[i]); 	
	}
	for(i=1;i<=10;i++)
	{
		if(arr[i]>MAX)
		{
			MAX=arr[i];
		}
	}
	printf("十个数中最大的数是：%d\n",MAX);
	return 0;
} 
