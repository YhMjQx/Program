//C���Թ涨������ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ�λ�õ�ָ����бȽ�
//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ��ָ����бȽ�
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
	}//��C���Թ涨Ӧ��ѡ��������forѭ���ķ�ʽ��ʵ�֣��������������forѭ����ʽ
	/*	
	for (p2 = &arr2[5]; p2 >= &arr2[0]; p2--,i--)
	{
		*p2 = 0;
		printf("%d ", arr2[i]);
	}
	*/
	return 0;
}