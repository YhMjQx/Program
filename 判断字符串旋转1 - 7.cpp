#include<stdio.h>
#include<string.h>
//strcat(arr1, arr2); ���Խ�arr2׷����arr1�ĺ��棬���Ǹú���������arr1׷��arr1����
//strncat(arr1, arr1, n); �ú���ͬ��Ҳ���ַ���׷�Ӻ�������������arr1׷�ӱ���ֻ�Ǳ�strcat��������һ���ַ������Ĳ�������
//strstr(arr1, arr2);�ú�����������arr1�����ҵ�arr2�ģ�Ҳ����˵��һ�����Ӵ��ĺ���,���᷵���ҵ����Ӵ������ַ��ĵ�ַ,���û�ҵ����ͷ���NULL
int Is_Round(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(str1, str2, len2);
	char* ret = strstr(str1, str2);
	if (ret==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
int main()
{
	char arr1[39] = "YhMjQx";
	char arr2[] = "jQxYhM";
	int ret = Is_Round(arr1, arr2);
	if (ret == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}