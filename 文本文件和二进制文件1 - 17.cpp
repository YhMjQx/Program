#include<stdio.h>
int main()
{
	//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	//wb：以二进制的形式写入文件
	fwrite(&a, 4, 1, pf);
	//第一个参数，要写入的数据的首地址
	//第二个参数，要写入的数据的字节大小
	//第三个参数，要写入的数据的个数
	//第四个参数，要写入的文件的文件指针
	fclose(pf);
	pf = NULL;
	//程序文件包括：
	//1.源程序文件，后缀为.c
	//2.目标文件，windows环境后缀为.obj
	//3.可执行程序，windows环境后缀为.exe 
	//字符一律以ASCLL形式存储，数值型数据既可以用ASCLL形式存储，也可以用二进制形式存储
	return 0;
}