#include<stdio.h>
#include<string.h>
int main()
{
	char ch1[] = "YhMjQx";
	char ch2[] = "YMQ";
	strncpy(ch1, ch2, 1);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 2);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 3);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 4);
	//�ɴ˿ɼ�������Ҫ���ǵ��ֽ���Ҳ���Դ����ҵ�source�ַ���
	//��ʱ�����ԭ�ַ��������а���'\0'���ǵ�Ŀ��ռ䣬��ʱ���൱��strcpy
	//ͬʱ������Ҫ�ĳ������Դ�ַ��������Ļ��ͻ���Ҳ�'\0'ֱ�����Ҳ������涨���ֽ���
	printf("%s\n", ch1);
	return 0;
}