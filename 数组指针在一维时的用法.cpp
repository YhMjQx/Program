#include<stdio.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* p = arr;//�����p�������pa�ǲ�ͬ�ģ������pֻ��һ���򵥵�ָ�룬�������pa������ָ��
	int (*pa)[10] = &arr;
	//&arr����������ĵ�ַ��arr��������Ԫ�صĵ�ַ����ʱpa=&arr��*pa=arr 
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));//�����p�������pa�ǲ�ͬ�ģ������pֻ��һ���򵥵�ָ�룬�������pa������ָ��
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