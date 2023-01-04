#include<stdio.h>
void Move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{	//从左寻找偶数
		while ((left < right) && (arr[left] % 2 == 1))//left < right是为了防止数组内全都是奇数
		{
			left++;
		}
		//从右找奇数
		while ((left < right) && (arr[right] % 2 == 0))//left < right是为了防止数组内全都是偶数
		{
			right--;
		}
		//对找到的奇数和偶数调换
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Move(arr, sz);
	Print(arr, sz);
	return 0;
}