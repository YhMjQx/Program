#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr;//这里的p和下面的pa是不同的，这里的p只是一个简单的指针，而下面的pa是数组指针
	int (*pa)[10] = &arr;
	//&arr是整个数组的地址，arr是数组首元素的地址，此时pa=&arr，*pa=arr 
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));//这里的p和下面的pa是不同的，这里的p只是一个简单的指针，而下面的pa是数组指针
	}printf("\n");


	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}printf("\n");


	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*pa)[i]);
	}printf("\n");


	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(*pa + i));
	}printf("\n");
	return 0;
}