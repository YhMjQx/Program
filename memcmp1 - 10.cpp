#include<stdio.h>
#include<string.h>
int main()
{
	//int memcpy(const void* ptr1,const void* ptr2.size_t num)�����size_t num�������޷������͵��ֽ���
	//memcpy�ķ������ͺ�strcmp�ķ���������һ����
	//ptr1<ptr2 - ����С��0�����֣�ptr1=ptr2 - ����0��ptr1>ptr2 - ���ش���0������
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 1, 2, 3, 8, 9 };
	int ret1 = memcmp(arr1, arr2, 12);
	printf("%d\n", ret1);
	int ret2 = memcmp(arr1, arr2, 13);
	printf("%d\n", ret2);
	return 0;

}