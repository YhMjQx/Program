#include<stdio.h>
#include<math.h> 
int main()
{
	int i; //��Ҫ�жϵ���
	int j; //����
	int flag=1; //������־λ
	for (i = 100; i < 201; i++)
	{
		flag = 1;
		for (j = 2; j < sqrt(i) + 1; j++)
		{
			if (i % j == 0)
				flag = 0;//��������������Ҿ���flagΪ0 
		}
		if (flag == 1)//������������Ҿ������ж������ǲ���1�����ڲ�������������������Ѿ���flag��Ϊ0�ˣ���������Ĵ�����ų��˲������������ 
			printf("������%d\n", i);
	}
	return 0;
}
