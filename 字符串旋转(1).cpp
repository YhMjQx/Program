#include<stdio.h>
#include<string.h>
#include<assert.h>
void Round(char* str, int k)
{
	assert(str != NULL);//assert()���ŵ��зŵ��Ǹ����ʽ
	int len = strlen(str);
	int i = 0;
	for (i = 0; i < k; i++)//����ѭ����k��Ϊ�˿�����ת���ٸ��ַ�
	{
		//��һ���������ַ��ſ�
		char tmp = *str;
		int j = 0;
		//�ڶ����������ַ�������ַ���ǰ�ƶ�
		for (j = 0; j < len - 1; j++)
		{
			*(str+j) = *(str + j+1);
		}
		//�����������ſյ����ַ��������һ���ַ���λ��
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char ch[] = "YhMjQx";
	int k = 3;
	Round(ch, k);
	printf("%s\n", ch);
	return 0;
}