#include<stdio.h>
int Add(int x, int y)//����һ���Ӻͺ�����������Ĵ���(�Զ��庯��-�Լ���ƣ�
{//ע�⣬�Զ��庯��Ҳ����Ҫʹ�ô�������������
	int z = x + y;
	return z;
}
int main()//��������printf��scanf���ǿ⺯����
{
	int sum;
	int num1 = 10;
	int num2 = 20;
	sum=Add(num1,num2);
	printf("%d\n", sum);
	int a = 100;
	int b = 200;
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}