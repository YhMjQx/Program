#include<stdio.h>
int main()
{
	//���ű��ʽ�������������μ��㣬���һ�����ű��ʽ�Ľ����Ϊ�������ű��ʽ�Ľ�� 
	int a=1;
	int b=2;
	int c=(a>b,a=b+10,a,b=a+1);
	printf("%d\n",c);
	return 0;
 } 
