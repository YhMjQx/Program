#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest && src);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	//strcat
	//Դ�ַ���������'\0'������Ŀ��ռ�����㹻����������Դ�ַ��������ݣ�
	//Ŀ��ռ������޸ġ�
	char arr1[39] = "abcdef";
	char arr2[] = "ghijklmn";
	//strcat(arr1, arr2);
	//printf("%s\n", arr1);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}