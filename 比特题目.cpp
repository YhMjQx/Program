#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));//ע��char��ȡֵ��Χ��0,1,2...127,-128,-127...-1,0��,�����ͬʱ��strlen�ҵ�\0��0����ͣ����
	return 0;
}