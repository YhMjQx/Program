#include<stdio.h>
int main()
{
	int i = 0;
	while (i <= 10)
	{
		i++;
		if (i == 5)
			continue;//����ִ��i=5���ѭ����������ݽ��Ϊ1 2 3 4 6 7 8 9 10 11,ֱ����ת��while�ж���һ�� 
		printf("%d ", i);
	}
	return 0;
}
//continue����ֹ����ѭ��continue����Ĵ��룬ֱ����ת��while�жϲ��֣�������һ��ѭ��
