#include<stdio.h>
int MAX(int x, int y)//ע��MAX����Ҳ��Ҫ��int������ 
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int num1 = 10;
	int num2 = 20;
	int max = 0;
	max = MAX(num1, num2);
	printf("�ϴ�ֵΪ%d\n", max);
	return 0;
}
//���������ⲿ�������ԣ������Կ��Ա�static���ν��иı� 
