#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
	//char* fgets(char* string,int n,FILE* stream)
	//char* string - 读出来的结果存放的位置
	//int n - 最大读取多少字节
	//FILE* stream - 从哪里读取数据
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
	//用puts函数打印的时候，puts会自动换行，而在文本内部，由于自己按了enter换行所以文本内部也存在换行，所以打印结果会出现中间空一行的样子
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