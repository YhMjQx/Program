#include<stdio.h>
#include<string.h>
#include<assert.h>
void reverse(char*str)
{
	assert(str);
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left < right)
	{ 
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
		//交换一对
	}
}
int main()
{
	char ch[39] = { 0 };
	gets(ch);//读取一行操作，例如scanf遇到空格就不再读取的情况，gets这个函数是不需要考虑的
	reverse(ch);
	printf("%s\n", ch);
	return 0;
}