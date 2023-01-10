#include<stdio.h>
#include<string.h>
int main()
{
	//int memcpy(const void* ptr1,const void* ptr2.size_t num)这里的size_t num依旧是无符号整型的字节数
	//memcpy的返回类型和strcmp的返回类型是一样的
	//ptr1<ptr2 - 返回小于0的数字；ptr1=ptr2 - 返回0；ptr1>ptr2 - 返回大于0的数字
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 1, 2, 3, 8, 9 };
	int ret1 = memcmp(arr1, arr2, 12);
	printf("%d\n", ret1);
	int ret2 = memcmp(arr1, arr2, 13);
	printf("%d\n", ret2);
	return 0;

}