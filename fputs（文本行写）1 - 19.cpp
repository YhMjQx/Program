#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//int fputs(const char* string,FILE* stream)
	//��һ��const char* stringд��FILE* stream
	//Ҳ����˵��һ����������д��һ���ļ�����������ָ������ļ���ָ��
	FILE* pf = fopen("text.txt", "w");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}


	//д�ļ�
	fputs("YhMjQx\n", pf);
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
	return 0;
}