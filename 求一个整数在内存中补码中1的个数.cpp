#include<stdio.h>
int main()
{
	int num = 0;
	int count = 0;
	printf("����������Ҫ���ҵ�����:>");
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
/*	int num = 0;
	int count = 0;
	printf("����������Ҫ���ҵ�����:>");
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 1)//�������1��Ҳ����˵�������ҵ������1����Ϊ���ǲ���Ҫ����1�ĸ�����
		{
			count++;
			num = num / 2;
		}
	}
	printf("%d\n", count);
	��δ��벻����������ȱ�ݡ�
*/