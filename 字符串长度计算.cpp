
#include<string.h>//����ͷ�ļ�������ʹ��strlen������
#include<stdio.h>
int main()
{//˫�����������ַ����������������ǵ����ַ���
	char arr1[] = "YhMjQx";//�ַ������Դ�\0�������ַ��������ı�־����ֵ����0��
	char arr2[] = { 'Y', 'h', 'M', 'j', 'Q', 'x', '\0' };//�����������ַ���������\0��������������\0����0��
	printf("%d\n", strlen(arr1));//strlen-string length���������ַ����ĳ��ȡ�
	printf("%d\n", strlen(arr2));
	return 0;	
}