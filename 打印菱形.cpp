#include<stdio.h>
int main()
{
	int line = 0;
	printf("��������Ҫ�����ε��ϰ벿�ֵ�����:>\n");
	scanf("%d", &line);
	int i = 0;
	//��ӡ�ϰ벿��
	for (i = 0; i < line; i++)
	{
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j < line -1- i; j++)
		{
			printf(" ");
		}
		//��ӡ *
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	//��ӡ�°벿��
	for (i = 0; i < line - 1; i++)
	{
		//��ӡ�ո�
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}