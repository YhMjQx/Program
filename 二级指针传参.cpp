#include<stdio.h>
void test(int **pp)//�ββ�����һ������ָ�룬����һ��ָ��ĵ�ַ���߶���ָ��
{
	printf("%d", **pp);
}
int main()
{
	int n = 39;
	int *p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	int *arr[10];//ָ�����鴫�Σ��������ŵ���һ��ָ�룬Ҳ����˵�����Ǵ�Ÿ�һ��ָ������������������Ԫ��(һ��ָ��)��ַ��
	test(arr);
	return 0;
}