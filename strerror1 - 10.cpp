#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	char* str = strerror(errno);
	printf("%s\n", str);
	//errno��һ��ȫ�ֵĴ��������
	//�����ԵĿ⺯����ִ�й����з����˴��󣬾ͻ�Ѷ�Ӧ�Ĵ����븳ֵ��errno����
	return 0;
}