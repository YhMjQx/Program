#include<stdio.h>
#include<string.h>
int main()
{
	//数组名是首地址，除了
	//sizeof(数组名)
	//&数组名
	int arr1[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(arr1));//16 sizeof(数组名) - 计算的是数组总大小，单位字节
	printf("%d\n", sizeof(arr1+0));//4 / 8a+0 - 是首元素地址 地址大小为4（32平台）8（64平台）
	printf("%d\n", sizeof(*arr1));//4 arr - 首元素地址 *arr - 首元素
	printf("%d\n", sizeof(arr1+1));//4 / 8 arr - 首元素地址 arr+1 - 第二个元素地址4 / 8
	printf("%d\n", sizeof(arr1[1]));//4  计算第二个元素大小
	printf("%d\n", sizeof(&arr1));//4 / 8&arr取出的是整个数组的地址，计算指针大小4 / 8 
	printf("%d\n", sizeof(*&arr1));//16 &arr - 取出整个数组地址 *&arr访问整个数组
	printf("%d\n", sizeof(&arr1+1));//4 / 8 跳过整个数组，但还是一个地址的大小
	printf("%d\n", sizeof(&arr1[0]));//4 / 8 第一个元素的地址
	printf("%d\n", sizeof(&arr1[0]+1));//4 / 8 第二个元素的地址

	printf("\n");
	char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr2));// 6 计算的是整个数组的大小
	printf("%d\n", sizeof(arr2+0));// 4 / 8 计算的是首元素地址的大小
	printf("%d\n", sizeof(*arr2));// 1 此时的arr2是首元素地址，*arr2就是首元素
	printf("%d\n", sizeof(arr2[1]));// 1 第二个元素的大小
	printf("%d\n", sizeof(&arr2));// 4 / 8 整个该数组地址的大小
	printf("%d\n", sizeof(&arr2+1));// 4 / 8 跳过整个数组之后的地址的大小
	printf("%d\n", sizeof(&arr2[0]+1));// 4 / 8 第二个元素的地址的大小

	printf("\n");
	printf("%d\n", strlen(arr2));// 随机值 从第一个元素地址开始往后数
	printf("%d\n", strlen(arr2 + 0));// 随机值 从第一个元素地址开始往后数
	printf("%d\n", strlen(&arr2[0] + 1));// 随机值-1，比前面的小一个，从第二个元素的地址开始往后数
	printf("%d\n", strlen(&arr2[1]));// 随机值-1，和上面一个情况相同
	/*  printf("%d\n", strlen(*arr2));	
	printf("%d\n", strlen(&arr2));
	printf("%d\n", strlen(&arr2 + 1));error*/

	printf("\n"); 
	const char arr3[] = "YhMjQx";
	printf("%d\n", sizeof(arr3));//7 整个数组所占字节大小
	printf("%d\n", sizeof(arr3+0));//4 / 8 首元素地址的的大小
	printf("%d\n", sizeof(*arr3));//1 首元素的大小
	printf("%d\n", sizeof(arr3[1]));//1 第二个元素的大小
	printf("%d\n", sizeof(&arr3));//4 / 8 整个数组地址的大小
	printf("%d\n", sizeof(&arr3+1));//4 / 8 跳过整个数组之后的地址的大小
	printf("%d\n", sizeof(&arr3[0]+1));//4 / 8 第二个元素地址的大小

	printf("\n");
	printf("%d\n", strlen(arr3));//6
	printf("%d\n", strlen(arr3 + 0));//6
	printf("%d\n", strlen(&arr3[0] + 1));//5
	printf("%d\n", strlen(&arr3[1]));//5
	/*	printf("%d\n", strlen(*arr3));注意strlen接收的类型应该是指针地址
	printf("%d\n", strlen(&arr3)); - 6
	printf("%d\n", strlen(&arr3 + 1));error*/

	printf("\n");
	char* p = "YhMjQx";//p中存的是Y的地址
	printf("%d\n", sizeof(p));//4 / 8 Y地址的大小
	printf("%d\n", sizeof(p+1));//4 / 8 h地址的大小
	printf("%d\n", sizeof(*p));//1 Y的大小
	printf("%d\n", sizeof(p[0]));//1Y的大小
	printf("%d\n", sizeof(&p));//4 / 8 Y地址的地址的大小
	printf("%d\n", sizeof(&p + 1));//4 / 8 h地址的地址的大小
	printf("%d\n", sizeof(&p[0] + 1));//4 / 8 h的地址的大小

	printf("\n");
	printf("%d\n", strlen(p));//6
	printf("%d\n", strlen(p + 1));//5
	printf("%d\n", strlen(&p[0]));//6
	//printf("%d\n", strlen(*p));error
	//printf("%d\n", strlen(&p));
	//printf("%d\n", strlen(&p + 1));
	printf("%d\n", strlen(&p[0] + 1));//5

	printf("\n");
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0]+1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a+1));//4
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16

	return 0;
}