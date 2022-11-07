#include<stdio.h>
int binary_search(int arr[], int k,int sz)
{                //本质上这的arr是一个指针
	//算法的实现
	int left = 0;
	int right = sz - 1;
	while (left <= right)//注意等号也要有哦
	{
		int mid = (left + right) / 2;//这句话一定只能在循环的里面，如果放在循环外面，则每一次的mid中间值的下标都不变，那就错误了
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;//找到了的时候，返回的是下标
		}
	}
	return -1;//找不到的时候返回的是-1
}
int main()
{
	int i = 0;
	//在一个有序数组中用二分查找找出某个数，如果找到了返回这个数的下标，如果没找到，返回-1
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	int ret = binary_search(arr, k,sz);//该函数到arr当中去查找，去查找的是k，然后查找后返回的结果（下标）赋给ret
	if (-1 == ret)                  //这里传过去的是数组中的第一个元素的地址
	{
		printf("找不到指定的数字\n");
	}
	else
	{
		printf("找到的下标是：%d \n", ret);
	}
	return 0;
}//先写这个函数怎么用，再去写函数