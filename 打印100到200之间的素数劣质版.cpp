#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)//�ж������ķ������Գ�����������2��i-1����������
	{
		int j = 0;
		for (j = 2; j < i; j++)//�Ž⣺j<=sqrt(i)���߰�sqrt(i)���i/2
		{
			if (0 == i%j)//�������Ҫ��ѭ����ѭ����,��˷Ž����forѭ����
			{
				break;//��Ϊ��ʱi�ܱ�j�����������i��������������ӡ
			}	
		}
		//Ϊʲô��ͻȻ�������أ����밡��break���������ǲ�����Ҫֱ���������forѭ��
		if (i == j)//�Ž⣺J>sqrt(i)���߰�sqrt(i)���i/2
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("\nһ����%d������ \n", count);
	return 0;

}
