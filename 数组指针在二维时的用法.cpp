#include<stdio.h>
void Print1(int arr[3][5], int x, int y)//参数是数组的形式
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void Print2(int(*p)[5], int x, int y)//p是一个指针，指向数组，每个数组5个元素,每个元素类型为int，参数是指针的形式
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		int j = 0;
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));//p是指针，指向的是二维数组的某一行，那么 * 操作后便找到了这一行的数组名
			printf("%d ", (*(p + i))[j]);
			printf("%d ", p[i][j]);
			printf("%d ", *(p[i] + j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
	Print1(arr, 3, 5);//arr - 数组名 - 首元素地址
	Print2(arr, 3, 5);
	return 0;
}
/*int arr[5] - arr是一个含有5个元素的整形数组
int* parr[10] - parr1是一个数组，数组有10个元素，每个元素的类型是int*，parr1是一个指针数组，该数组用来存放指针变量
int(*parr2)[10] - parr2是一个指针，该指针指向了一个数组，该数组有10个元素，每个元素的类型是int，parr2是一个数组指针
int(*parr3[10])[5] - parr3是一个数组，该数组含有10个元素，每个元素的类型是（数组）指针，每个指针指向的数组有5个元素，每个元素类型为int*/