#include<stdio.h>
int MAX(int x, int y)
{
	int  exp(x > y ? x : y);
	return exp;
	/*if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
	��Ҳ��һ�ַ�����������Ŀ���������Ӽ��
*/
}
int main()
{
	int a = 10;
	int b = 20;
	int max= MAX(a,b);
	printf("%d ", max);
	return 0;
}