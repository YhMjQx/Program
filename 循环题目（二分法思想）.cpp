#include<stdio.h>
int main()
{
	int arr[] = {  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11 };//输入的k是数组里面的数
	int k = 0;

	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入k的值 (k的值应在0到10之间) :");
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
		else//
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