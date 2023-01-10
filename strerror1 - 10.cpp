#include<stdio.h>
#include<errno.h>
#include<string.h>
int main()
{
	char* str = strerror(errno);
	printf("%s\n", str);
	//errno是一个全局的错误码变量
	//当语言的库函数在执行过程中发生了错误，就会把对应的错误码赋值到errno当中
	return 0;
}