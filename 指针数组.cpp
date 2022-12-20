#include<stdio.h>
int main()
{
	/*指针数组 -- 用来存放指针的数组
	int arr[10] = { 0 };整形数组 -- 用来存放整形的数组
	char ch[5] = { 0 };字符数组 -- 用来存放字符的数组
	int* parr[6];用来存放整形指针的数组 -- 指针数组
	char* pch[6];用来存放字符指针的数组 -- 指针数组*/
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 2, 3, 4, 5, 6 };
	int arr3[] = { 3, 4, 5, 6, 7 };
	int* parr[] = { arr1, arr2, arr3 };//这个形式是一个指针数组 
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
		}
		printf("\n");
	}
	return 0;
}
