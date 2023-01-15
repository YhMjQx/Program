#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void*calloc(size_t num , size_t size)
	//size_t num - 元素的个数
	//size_t size - 每个元素的字节大小
	//free会用来释放动态开辟的空间的
	//calloc功能是为num个大小为size的元素开辟一块空间，并且把每一字节初始化为0
	//calloc与malloc的区别在于calloc再返回地址之前会把申请的空间的每个字节初始化为0
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)//注意不要越界访问，开辟多少空间就用多少空间
		{
			printf("%d ", *(p + i));
		}
		printf("\n");
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
		printf("\n");
	}
	free(p);//这里释放的应该是动态空间开辟的内存空间，也就是堆区内部的内存空间
	p = NULL;
	return 0;
}