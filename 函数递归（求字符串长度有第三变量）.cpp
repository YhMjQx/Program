#include<stdio.h>
#include<string.h>
int My_strlen(char* str)//str���д洢����arr��һ��Ԫ�صĵ�ַ
{
	int count = 0;
	while (*str != '\0')//��Ҫѭ������ʵ�֣�������ַ�������\0
	{
		//������ʹ��str������count������ѭ������ʵ�֣�count��Ҫ����str��++��++��
		count++;
		str++;//�����ǵ�ַ��һ������ʹ�жϽ�����һ���ַ������ǽ�����֮���һ
	}
	return count;
}
int main()
{
	char arr[] = "hy39";//h y 3 9 \0
	printf("%d\n", My_strlen(arr));
	return 0;
}