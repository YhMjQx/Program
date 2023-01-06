#include<stdio.h>
#include<string.h>
#include<assert.h>
//������ת��
//YhM jQx - ��һ��������Ҫ��ת���ַ���������������ת
//MhY xQj - �ڶ�������ʣ�µ��ַ�����ת
//jQx YhM - ��������ַ����ٴη�ת
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
	reverse(str,str+k-1);//�������
	reverse(str+k,str+len-1);//�����ұ�
	reverse(str,str+len-1);//��������
}
int main()
{
	char ch[] = "YhMjQx";
	int k = 3;
	Round(ch, k);
	printf("%s\n", ch);
	return 0;
}