//空间发咋读是对一个算法过程中临时额外暂用空间大小的量度
//一般情况下，空间复杂度计算的就是变量的个数，主要通过函数在运行时显式申请的额外空间来确定
//具体事例在冒泡排序，递归斐波那契数列，递归n的阶乘里面看
//面试题：消失的数字
	//一个数组包含[0,n]的所有整数，但唯独缺了一个，请找出这个消失的数字，且时间复杂度是O(N)
	//思路一：使用qsort将数组排序，然后判断后一个数是不是前一个数加一就好了，如果是就打印这个数
	//		qsort的时间复杂度是O(n*logN)
	//思路二：将[0,n]内的所有数字加起来，然后减掉这个数组的所有元素，剩下的就是消失的数字了
	//		时间复杂度为O(N)，空间复杂度为O(1)
	//思路三：将这个数组内下标为0的数字设为0，然后剩下的数字和下标一一对应，如果发现有没对应上的，那么这个数字就是消失的数字
	//		时间复杂度是O(N)，空间复杂度是O(N)
	//思路四：设X = 0，用X先跟[0,n]内的所有数字异或一遍，然后再跟数组内的所有元素异或一遍，剩下的X就是缺失的数字
#include<stdio.h>
//int check_num(int *arr, int n)
//{
//	int x = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		x = x^i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		x = x^arr[i];
//	}
//	return x;
//}
//int main()
//{
//	int arr[] = { 0, 1, 2, 3, 4, 5, 9, 6, 7 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	printf("%d\n", check_num(arr,sz));
//	return 0;
//}
//面试题：旋转数组
//给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数
//要求：尽可能多的想出更多解决办法，至少有三种不同的方法可以解决这个问题，挑选其中空间复杂度为O(1)的原地算法解决
//思路一：首先将最后一个元素置空，然后将前面的元素都往后移动一位
//void Round(int(*parr)[10],int k,int sz)
//{
//	for (int i = 0; i < k; i++)
//	{
//		int temp = *(parr[sz - 1]);
//		for (int j = 0; j < sz - 1; j++)
//		{
//			*(parr[sz - j - 1]) = *(parr[sz - j - 2]);
//		} 
//		*(parr[0]) = temp;
//	}
//}//时间复杂度是O(N*K)，空间复杂度是O(1)，但是这个算法不知道是哪错了

//思路二：eg：[0,1,2,3,4,5,6,7,8,9],设有n个元素，比如我要旋转k个元素，那么我可以将前n-k个元素逆置
		//然后将后k个元素逆置，最后将整个数组逆置一遍，得到的结果就是整个数组逆置后的结果
void Reverse(int* parr, int left, int right)
{
	while (left < right)
	{
		int temp = parr[left];
		parr[left] = parr[right];
		parr[right] = temp;
		left++;
		right--;
	}
}//时间复杂度是O(N)，空间复杂度是O(1)
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int(*parr)[10] = &arr;
	if (k >= sz)
		k %= sz;
	Reverse(arr, 0, sz - k - 1);//逆置前n-k个元素
	Reverse(arr, sz - k , sz - 1);//逆置后k个元素
	Reverse(arr, 0, sz - 1);//逆置整个数组
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
