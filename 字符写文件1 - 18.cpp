#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE* pfWrite = fopen("TEXT.txt", " w");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//д�ļ�
	fputc('Y', pfWrite);
	fputc('h', pfWrite);
	fputc('M', pfWrite);
	fputc('j', pfWrite);
	fputc('Q', pfWrite);
	fputc('x', pfWrite);
	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
	return 0;
}