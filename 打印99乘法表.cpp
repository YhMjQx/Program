#include<stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 9; i++)//ȷ����ӡ9��
	{
		int j = 1;
		for (j = 1; j <= i; j++)//ȷ����ӡ9��
		{
			printf("%d*%d= %-2d\t", i, j, i*j);//%-2d������룬%2d���Ҷ���,\t��ˮƽ�Ʊ��
		}
		printf("\n");//ÿһ����ѭ������֮�����һ�����в���
	}
	return 0;
}