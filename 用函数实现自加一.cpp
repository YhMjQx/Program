#include<stdio.h>
void Add(int* p)//int Add(int* p)
{				//{
	(*p)++;		//(*p)++;
				//return 1;
}				//}
int main()
{//Ҫ��ͨ���ⲿ�Զ��庯�����ı��������ڲ�Ԫ�ص�ֵ��Ӧ��ͨ����ַ����ʽ
	int num = 0;
	Add(&num);
	printf("%d ", num);
	Add(&num);
	printf("%d ", num);
	Add(&num);
	printf("%d ", num);
	return 0;
}