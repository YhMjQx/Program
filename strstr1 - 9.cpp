#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[] = "abcdefabcdef";
	const char arr2[] = "bcde";
	char* ret = strstr(arr1, arr2);
	//char* strstr(char* ,const char*),���ص���һ��ָ�룬�����������Ŀ�����ص���abcdefabcdef���еĵ�һ��b�ĵ�ַ
	if (ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}