#include<stdio.h>
#include<string.h>
#include<assert.h>
//������ת��
//YhM jQx - ��һ��������Ҫ��ת���ַ���������������ת
//MhY xQj - �ڶ�������ʣ�µ��ַ�����ת
//jQx YhM - ��������ַ����ٴη�ת
void reverse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	int i = 0;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void Round(char* str, int k)
{
	assert(str != NULL);
	int len = strlen(str);
	assert(k < len);
	reverse(str, str + k - 1);//�������
	reverse(str + k, str + len - 1);//�����ұ�
	reverse(str, str + len - 1);//��������
}
int If_Round(char* arr1, char* arr2)
{
	int i = 0;
	int len = strlen(arr1);
	for (i = 0; i < len; i++)
	{
		//ÿ����ת֮��arr1���ᷢ���仯������ÿ����תһ���ַ����Ƚϣ�����ٷ��ɵý��
		Round(arr1, 1);
		//������ַ�������򷵻�0����arr1<arr2�򷵻ظ�������arr1>arr2�򷵻�����
		int ret = strcmp(arr1, arr2);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "YhMjQx";
	char arr2[] = "jQxYhM";
	int ret = If_Round(arr1, arr2);
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