#include<stdio.h>
void Print(int* p, int sz)//Ҳ����˵��һ��ָ�봫��ֻ����һ��ָ����վ��У�ͬʱ��һ��ָ�뻹�ܽ��ձ����ĵ�ַ��������ĵ�ַ
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
