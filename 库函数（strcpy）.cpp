#include<stdio.h>
#include<string.h>
int main()
{
	//strcpy - string copy - �ַ�������
	//strlen - string length - ���ַ�������#include<string.h>
	char arr1[] = { "����ǿ\n" };
	char arr2[] = { "˭��������" };
	strcpy(arr2, arr1);//�����ߵ��ַ��������󸲸ǵ�ǰ����
	printf("%s", arr2);
	return 0;
}