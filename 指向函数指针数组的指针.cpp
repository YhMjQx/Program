#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int arr[10] = { 0 };
	int (*p)[10]=&arr;//����ָ��
	int(*pf)(int, int);//����ָ��
	int(*pfArr[4])(int, int);//����ָ������
	int(*(*ppfArr)[4])(int, int)=&pfArr;//ָ����ָ�������ָ��
	//pfArr��һ������ָ�����飬ָ���������4��Ԫ�أ�ÿ��Ԫ��Ϊint
	//ppfArr��һ������ָ�룬��ָ���������4��Ԫ��
	//ָ��������ÿ��Ԫ�ص������Ǻ���ָ��int(*)(int, int)
	return 0;
}