#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1,5,7 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组的元素个数，为什么要计算个数呢，因为当数组元素个数改变之后，改代码依旧能用
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];//异或的使用，eg：3^3=0 5^5=0 a^a=0 0^3=3 0^a=a 3^5^3=5 3^3^5=5即：异或是符合交换律的。
	}
	printf("单身数字=%d", ret);
	return 0;
}