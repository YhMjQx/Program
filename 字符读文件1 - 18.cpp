#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE* pfRead = fopen("TEXT.txt", " r");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	} 
	//���ļ�
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	printf("%c",fgetc(pfRead));
	//�ر��ļ�
	fclose(pfRead);
	pfRead = NULL;
	return 0;
}