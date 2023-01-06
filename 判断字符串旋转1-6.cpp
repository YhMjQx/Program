#include<stdio.h>
#include<string.h>
#include<assert.h>
//三步翻转法
//YhM jQx - 第一步：将需要翻转的字符数隔开，独自旋转
//MhY xQj - 第二步：将剩下的字符串旋转
//jQx YhM - 随后将整个字符串再次翻转
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
	reverse(str, str + k - 1);//逆序左边
	reverse(str + k, str + len - 1);//逆序右边
	reverse(str, str + len - 1);//逆序整体
}
int If_Round(char* arr1, char* arr2)
{
	int i = 0;
	int len = strlen(arr1);
	for (i = 0; i < len; i++)
	{
		//每次旋转之后arr1都会发生变化，所以每次旋转一个字符并比较，用穷举法可得结果
		Round(arr1, 1);
		//如果两字符串相等则返回0，若arr1<arr2则返回负数，若arr1>arr2则返回正数
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