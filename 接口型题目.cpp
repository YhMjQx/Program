//接口型题目
//1.不需要写头文件，主函数等等
//2.提交了以后，会跟OJ服务器上已经准备好的代码合并，再编译运行
//测试用例：通过参数传过来的
//结果：一般是通过返回值拿的，也有可能是输出型参数
#include<stdio.h>

//题目：给一个nums和一个值val，你需要原地移出所有数值等于val的值，并返回数组的新长度
//eg：nums[6] = { 1, 3, 3, 4, 3, 5 }, val = 3;
//思路一：一一遍历数组，从头开始，当遇到val的时候，将val之后的所有数向前移动一位
	//只不过此时的时间复杂度是O(N^2)，因为考虑最坏的情况的时候，数组中大部分或者全部都是val
//思路二：建立一个新的数组，从头往后遍历，然后将不是val的值，放在这个新的数组里面，再把tmp拷贝回去
	//此时时间复杂度是O(N)，空间复杂度是O(N)
//思路三：给两个下标，例如src和dest，src去找nums数组中不等于val的值，放在dest指向的位置去，然后src++，dest++
	//此时时间复杂度是O(N)，空间复杂度是O(1)
//int removeElement(int* nums, int numsize, int val)
//{
//	int src = 0, dest = 0;
//	while (src < numsize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dest] = nums[src];
//			src++;
//			dest++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dest;
//}

//题目：给你一个有序数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度
//eg:nums = {0,0,1,1,1,2,2,3,3,4}
//int removeDuplicates(int* nums, int numsize)
//{
	//首先我要判断数组是否为空，如果为空根本不需要执行
//	if (numsize == 0)
//		return 0;
//	int dest = 0, i = 0, j = 1;
//	while (j < numsize)
//	{
//		if (nums[i] == nums[j])
//		{
//			j++;
//		}
//		if (nums[i] != nums[j])
//		{
//			nums[dest] = nums[i];
//			dest++;
//			i = j;
//			j++;
//		}
//	}
//	nums[dest] = nums[i];
//	dest++;
//	return dest;
//}
//int main()
//{
//	int arr[3] = { 1, 1, 2 };
//	int len = removeDuplicates(arr,3);
//	printf("%d\n", len);
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


//题目：有序数组合并,即，将两个数组合并了之后，还能保持一定的顺序
//eg：输入：nums1 = { 1, 2, 3, 0, 0, 0 };    nums2 = { 2, 5, 6 };m是nums1的有效数据的个数，n是nums2的元素个数
//输出：[1,2,2,3,5,6]
void merge(int* nums1, int* nums2, int m, int n)//时间复杂度是O(M+N)，空间复杂度是O(1)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end1 < 0 && end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
int main()
{
	int nums1[6] = { 1, 2, 3, 0, 0, 0 };
	int nums2[3] = { 2, 5, 6 };
	merge(nums1, nums2, 3, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	return 0;
}