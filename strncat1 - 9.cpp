#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[39] = "YMQ love ";
	char arr2[] = "HJX";
	strncat(arr1, arr2, 3);
	printf("%s\n", arr1);
	//��������ǲ����ַ����������Ƶ��ַ������������������ֽ������Դ���Դ�ַ����ĳ���
	//�ú���ÿ��׷����󶼻��Զ���'\0'������Ҫ����ֽ�����������ĳ��ȣ���Ҳֻ��һ��'\0'
	return 0;
}