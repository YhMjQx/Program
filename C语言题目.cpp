#include<stdio.h>
int sum(int a)
{
	int c = 0;
	static int b = 3;//static���ξֲ��������ı�ֲ��������������ڣ�ʹ��b�ı����ͻ��{}�����ı䣬�Ӷ�����ʹ��
	c += 1;//��c��û��static���Σ����ǵڶ��ε�c������0
	b += 2;//��һ��b��Ϊ5��Ȼ���ֱ�Ϊ7...
	return(a + b + c);
}
int main()
{
	int a = 2;//���aֻ�������{}��ʹ��
	int i = 0;
	i++;
	for (i = 1; i < 5; i++)
	{
		printf("%d\n", sum(a));
	}
	return 0;
}