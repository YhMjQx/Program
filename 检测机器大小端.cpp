#include<stdio.h>
/*void cheak_sys()
{
	int a = 1;
	char* p = (char*)&a;
	if (*p == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
}*/
/*int cheak_sys()
{
	int a = 1;
	char* p = (char*)&a;
	return *p;
}*/
int cheak_sys()
{
	int a = 1;
	return *(char*)&a;
}//ָ������������ 1.ָ�����;����˽����ò������ܷ��ʼ����ֽڣ�char*�ܷ���1���ֽڣ�int*�ܷ���4���ֽ�
 // 2.ָ�����;�����ָ��+1����-1ʱ���Ӽ��ĵ����Ǽ����ֽڣ�char* p��p+1����һ���ֽڣ�int* p��p+1����4���ֽ�
int main()
{
	int a = 1;
	int ret=cheak_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;

}