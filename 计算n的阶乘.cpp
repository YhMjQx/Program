#include<stdio.h>
int main()
{
	int i = 0;
	long  a = 1;//������ʼ��ֵ������0����Ϊ0�����κ�������0
	int n = 0;
	printf("������n��ֵ");
	scanf("%d", &n);
	for (i = 1;i<=n;i++)
	{
		a*=i;//a=a*i
	}
	printf("�׳�=%d", a);
	


	return 0;
}