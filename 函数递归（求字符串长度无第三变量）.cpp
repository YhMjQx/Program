#include<stdio.h>
#include<string.h>
//My_strlen("hy39")
//1+My_strlen("y39")
//1+1+My_strlen("39")
//1+1+1+My_strlen("9")
//1+1+1+1+My_strlen("")
//1+1+1+1+0=4
int My_strlen(char* str)//�ݹ�ķ�ʽ���Ѵ��»�С
{
	if (*str != '\0')
		return 1 + My_strlen(str + 1);//��ͣ�صݼ��ַ����ĳ���ÿ�ݼ�һ��ǰ��Ӹ�һ���������������
	else
		return 0;
}
int main()
{
	char arr[] = "hy39";//h y 3 9 \0
	printf("����=%d\n", My_strlen(arr));
	return 0;
}