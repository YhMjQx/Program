#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//int fseek(FILE* stream,long int offset,int origin)
	//FILE* stream - pf
	//long int offset - ƫ����
	//int origin - �ļ�ָ�뵱ǰλ��
	//SEEK_CUR - �ļ�ָ��ĵ�ǰλ��
	//SEEK_SET - �ļ�����ʼλ��
	//SEEK_END - �ļ���ĩβλ��
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//��λ�ļ�ָ��
	fseek(pf, 2, SEEK_CUR);
	char ch = fgetc(pf);
	printf("%c\n", ch);
	fclose(pf);
	pf = NULL;
	return 0;
}