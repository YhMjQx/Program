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
		//����һ��
	}
}
int main()
{
	char ch[39] = { 0 };
	gets(ch);//��ȡһ�в���������scanf�����ո�Ͳ��ٶ�ȡ�������gets��������ǲ���Ҫ���ǵ�
	reverse(ch);
	printf("%s\n", ch);
	return 0;
}