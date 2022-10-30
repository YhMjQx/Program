#include<stdio.h>
int main()
{
	int arr[] = {  1, 3, 5, 7, 9, 2, 4, 8, 6, 10,11 };//输入的k是数组里面的数
	int k = 0;

	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入k的值 (k的值应在该数组之间) :");
	scanf("%d", &k);
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;//
		if (arr[mid] > k)//
		{//
			right = mid - 1;//
		}//
		else if (arr[mid] < k)//
		{//
			left = mid + 1;//
		}//
		else//arr[i]既不比k大又不比k小，则只能arr[i]=k，只需输出此时的i即可 
		{//
			printf("找到了，下标是：%d", mid);//
			break;//
		}//
		//标注了的是这个循环体的重要组成部分
	}
	if (left>right)
	{
		printf("找不到了");
	}
	return 0;
}
