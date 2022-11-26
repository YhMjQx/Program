#include<stdio.h>
int main()
{
	int a=0;
	int arr[]={1,2,3,4,5,6,7,8,9};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int left=0;
	int right=sz-1;
	printf("请输入您需要查找的数字:>");
	scanf("%d",&a);
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a<arr[mid])
		{
			right=mid-1;
		}
		else if(a>arr[mid])
		{
			left=mid+1;
		}
		else
		{
		printf("找到了，下标是%d",mid);
		break; 
		} 
		
	}
	if(left>right)
	{
		printf("找不到了\n");
	}
	return 0;
}
