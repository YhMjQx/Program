#include<stdio.h>
#include<string.h>
int main()
{
	//���������׵�ַ������
	//sizeof(������)
	//&������
	int arr1[] = { 1, 2, 3, 4 };
	printf("%d\n", sizeof(arr1));//16 sizeof(������) - ������������ܴ�С����λ�ֽ�
	printf("%d\n", sizeof(arr1+0));//4 / 8a+0 - ����Ԫ�ص�ַ ��ַ��СΪ4��32ƽ̨��8��64ƽ̨��
	printf("%d\n", sizeof(*arr1));//4 arr - ��Ԫ�ص�ַ *arr - ��Ԫ��
	printf("%d\n", sizeof(arr1+1));//4 / 8 arr - ��Ԫ�ص�ַ arr+1 - �ڶ���Ԫ�ص�ַ4 / 8
	printf("%d\n", sizeof(arr1[1]));//4  ����ڶ���Ԫ�ش�С
	printf("%d\n", sizeof(&arr1));//4 / 8&arrȡ��������������ĵ�ַ������ָ���С4 / 8 
	printf("%d\n", sizeof(*&arr1));//16 &arr - ȡ�����������ַ *&arr������������
	printf("%d\n", sizeof(&arr1+1));//4 / 8 �����������飬������һ����ַ�Ĵ�С
	printf("%d\n", sizeof(&arr1[0]));//4 / 8 ��һ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&arr1[0]+1));//4 / 8 �ڶ���Ԫ�صĵ�ַ

	printf("\n");
	char arr2[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d\n", sizeof(arr2));// 6 ���������������Ĵ�С
	printf("%d\n", sizeof(arr2+0));// 4 / 8 ���������Ԫ�ص�ַ�Ĵ�С
	printf("%d\n", sizeof(*arr2));// 1 ��ʱ��arr2����Ԫ�ص�ַ��*arr2������Ԫ��
	printf("%d\n", sizeof(arr2[1]));// 1 �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr2));// 4 / 8 �����������ַ�Ĵ�С
	printf("%d\n", sizeof(&arr2+1));// 4 / 8 ������������֮��ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&arr2[0]+1));// 4 / 8 �ڶ���Ԫ�صĵ�ַ�Ĵ�С

	printf("\n");
	printf("%d\n", strlen(arr2));// ���ֵ �ӵ�һ��Ԫ�ص�ַ��ʼ������
	printf("%d\n", strlen(arr2 + 0));// ���ֵ �ӵ�һ��Ԫ�ص�ַ��ʼ������
	printf("%d\n", strlen(&arr2[0] + 1));// ���ֵ-1����ǰ���Сһ�����ӵڶ���Ԫ�صĵ�ַ��ʼ������
	printf("%d\n", strlen(&arr2[1]));// ���ֵ-1��������һ�������ͬ
	/*  printf("%d\n", strlen(*arr2));	
	printf("%d\n", strlen(&arr2));
	printf("%d\n", strlen(&arr2 + 1));error*/

	printf("\n"); 
	const char arr3[] = "YhMjQx";
	printf("%d\n", sizeof(arr3));//7 ����������ռ�ֽڴ�С
	printf("%d\n", sizeof(arr3+0));//4 / 8 ��Ԫ�ص�ַ�ĵĴ�С
	printf("%d\n", sizeof(*arr3));//1 ��Ԫ�صĴ�С
	printf("%d\n", sizeof(arr3[1]));//1 �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr3));//4 / 8 ���������ַ�Ĵ�С
	printf("%d\n", sizeof(&arr3+1));//4 / 8 ������������֮��ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&arr3[0]+1));//4 / 8 �ڶ���Ԫ�ص�ַ�Ĵ�С

	printf("\n");
	printf("%d\n", strlen(arr3));//6
	printf("%d\n", strlen(arr3 + 0));//6
	printf("%d\n", strlen(&arr3[0] + 1));//5
	printf("%d\n", strlen(&arr3[1]));//5
	/*	printf("%d\n", strlen(*arr3));ע��strlen���յ�����Ӧ����ָ���ַ
	printf("%d\n", strlen(&arr3)); - 6
	printf("%d\n", strlen(&arr3 + 1));error*/

	printf("\n");
	char* p = "YhMjQx";//p�д����Y�ĵ�ַ
	printf("%d\n", sizeof(p));//4 / 8 Y��ַ�Ĵ�С
	printf("%d\n", sizeof(p+1));//4 / 8 h��ַ�Ĵ�С
	printf("%d\n", sizeof(*p));//1 Y�Ĵ�С
	printf("%d\n", sizeof(p[0]));//1Y�Ĵ�С
	printf("%d\n", sizeof(&p));//4 / 8 Y��ַ�ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&p + 1));//4 / 8 h��ַ�ĵ�ַ�Ĵ�С
	printf("%d\n", sizeof(&p[0] + 1));//4 / 8 h�ĵ�ַ�Ĵ�С

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