#include<stdio.h>
#include<string.h>
#include<assert.h>
//三步翻转法
//YhM jQx - 第一步：将需要翻转的字符数隔开，独自旋转
//MhY xQj - 第二步：将剩下的字符串旋转
//jQx YhM - 随后将整个字符串再次翻转
void reverse(char* left,char* right)
{
	assert(left!=NULL);
	assert(right!=NULL);
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
	assert(str!=NULL);
	int len = strlen(str);
	assert(k < len);
	reverse(str,str+k-1);//逆序左边
	reverse(str+k,str+len-1);//逆序右边
	reverse(str,str+len-1);//逆序整体
}
int main()
{
	char ch[] = "YhMjQx";
	int k = 3;
	Round(ch, k);
	printf("%s\n", ch);
	return 0;
}