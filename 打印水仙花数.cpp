#include<stdio.h>
#include<math.h>
int main()
{ 
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//�ж�һ�����Ƿ�Ϊˮ�ɻ���
		//1.�����������λ��
		int n = 1;
		int sum = 0;
		int tmp = i;
		while (tmp /= 10)
		{
			n++;
		}
		//2.�����������ÿλ����n�η�֮��
		tmp = i;
		while (tmp)
		{
			sum += pow((float)(tmp % 10), n);
			tmp /= 10;
		}
		//�Ƚ�i��sum������
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}