#include<stdio.h>
#include<string.h>
int main()
{
	//memset(���� a,���� b,���� c),��1ָ���Ŀռ��е�ǰc���ֽڵ����ݻ���ָ����b�����ֵ
	char arr[] = "iloveyou";
	memset(arr, '*',1 );//�м�Ҫ����int�ͣ�*��ӡ��������ASCII��ֵ
	printf("%s\n", arr);
	return 0;
}