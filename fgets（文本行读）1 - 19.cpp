#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//char* fgets(char* string,int n,FILE* stream)
	//char* string - �������Ľ����ŵ�λ��
	//int n - ����ȡ�����ֽ�
	//FILE* stream - �������ȡ����
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	char buf[1024] = { 0 };
	fgets(buf, 1024, pf);
	//printf("%s", buf);
	puts(buf);
	//��puts������ӡ��ʱ��puts���Զ����У������ı��ڲ��������Լ�����enter���������ı��ڲ�Ҳ���ڻ��У����Դ�ӡ���������м��һ�е�����
	fgets(buf, 1024, pf);
	//printf("%s", buf);
	puts(buf);

	fgets(buf, 1024, pf);
	//printf("%s", buf);
	puts(buf);

	fgets(buf, 1024, pf);
	//printf("%s", buf);
	puts(buf);
	fclose(pf);
	pf = NULL;
	return 0;
}