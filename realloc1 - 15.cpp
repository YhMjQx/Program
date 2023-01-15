#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void* realloc(void* memblock,size_t size)
	//void* memblock - 之前开辟的内存开（需要改变的内存块的地址）
	//size_t size - 新开辟之后的字节大小
	int* p = (int *)malloc(20);
	if (p == NULL)//这里很重要，一定要判断一下开辟是否成功
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)//注意不要越界访问，开辟多少空间就用多少空间
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	//使用malloc开辟了一个20个字节大小的空间，假设这里20个字节的空间不够用，希望能开辟40个字节大小的空间
	//这里就可以用realloc来调整动态内存分配
	//realloc函数的使用注意事项：
	//1.如果p指向的空间后有足够的内存空间可以追加，则直接追加，完成之后返回p
	//2.如果p指向的空间后没有足够的内存空间可以追加，则realloc会重新开辟一个新的满足代码要求的内存区域
	//  并且把原来内存空间内的数据拷贝放到这个新的内存空间，然后把旧的空间地址释放掉，最后返回这个新的内存空间的起始地址
	//3.得用一个新的指针变量来接收realloc函数的返回值
	int* pos = (int *)realloc(p, 40);
	if (pos != NULL)
	{
		p = pos;
		int i = 0;
		for (i = 5; i < 10; i++)//注意不要越界访问，开辟多少空间就用多少空间
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);//这里释放的应该是动态空间开辟的内存空间，也就是堆区内部的内存空间
	p = NULL;
	return 0;
}