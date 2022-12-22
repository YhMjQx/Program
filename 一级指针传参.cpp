#include<stdio.h>
void Print(int* p, int sz)//也就是说，一级指针传参只需用一级指针就收就行，同时，一级指针还能接收变量的地址，和数组的地址
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	Print(p, sz);
	return 0;
}
