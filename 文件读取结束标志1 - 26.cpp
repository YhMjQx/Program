#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		//perror("�Լ����");���ú�strerrorһ�����÷����򵥣����������Լ���ӵ����ݺ������ð�ź�һ���ո�
		return 0;
	}
	char ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		//fputc(ch,pf);
		putchar(ch);
	}
	printf("\n");
	if (ferror(pf))
	{
		printf("error of file!");
	}
	else if (feof(pf))
	{
		printf("end of file!");
	}
	fclose(pf);
	pf = NULL;
	return 0;
}
//feofӦ���ڵ��ļ���ȡ������ʱ���ж��Ƿ�����Ϊ�������ļ�ĩβ��EOF������
//1.�ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�ΪEOF��fgetc��������NULL��fgets��
//���磺fgetc�����ж��Ƿ�ΪEOF��fgets�����ж��Ƿ�ΪNULL
//2.�������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���
//���磺fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ���