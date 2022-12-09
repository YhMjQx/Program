//C语言规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针进行比较
//但是不允许与指向第一个元素之前的那个内存的指针进行比较
#include<stdio.h>
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int* p1 = arr1;
	int* p2 = arr2;
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int i = sz-1;
	for (p1 = &arr1[5]; p1 > &arr1[0];i--)
	{
		*--p1 = 0;
		printf("%d ", arr1[i]);
	}//由C语言规定应该选择用这种for循环的方式来实现，尽量避免下面的for循环方式
	/*	
	for (p2 = &arr2[5]; p2 >= &arr2[0]; p2--,i--)
	{
		*p2 = 0;
		printf("%d ", arr2[i]);
	}
	*/
	return 0;
}