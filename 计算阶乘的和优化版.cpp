#include<stdio.h>
int main()
{
	int i = 0;
	long  a = 1;//Ҫ�����˵����ɲ�����0
	int n = 0;
	int b = 0;
	int sum = 0;
	printf("������b��ֵ");
	scanf("%d", &b);
	for (n = 1; n <= b; n++)
	{
			a = a*n;
		sum = sum + a;
	}
	printf("sum=%d", sum);
	return 0;
}