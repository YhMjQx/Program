#include<stdio.h>
int main()
{
	int arr[10];
	int MAX=0;
	int i=0;
	for(i=1;i<=10;i++)
	{
		printf("����������:>");
		scanf("%d",&arr[i]); 	
	}
	for(i=1;i<=10;i++)
	{
		if(arr[i]>MAX)
		{
			MAX=arr[i];
		}
	}
	printf("ʮ�������������ǣ�%d\n",MAX);
	return 0;
} 
