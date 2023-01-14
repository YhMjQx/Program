#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void* malloc(size_t size)
	int* p = (int *)malloc(40);//开辟40个字节的空间，若果malloc开辟空间失败就会返回一个NULL，malloc本来的返回类型应该是void*，所以一般情况下我是需要进行强制类型转换的
	if (p = NULL)
	{
		printf("%s\n", strerror(errno));
		//如果程序执行过程中发生了错误，会将错误码赋给errno，然后通过strerror函数会找到错误码对应的错误信息，然后我就可以打印出来
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//每当动态申请的空间不再使用的时候，就应该用free还给操作系统，但是单单用一个free只能将申请到的空间归还，但是指针所指向的位置依旧没有发生改变，于是，归还之后应当给指针赋成NULL
	free(p);
	p = NULL;
	return 0;
}