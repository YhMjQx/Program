#include<stdio.h>
#include<string.h>
int main()
{
	//memset(类型 a,类型 b,类型 c),将1指定的空间中的前c个字节的内容换成指定的b的这个值
	char arr[] = "iloveyou";
	memset(arr, '*',1 );//中间要的是int型，*打印的是他的ASCII码值
	printf("%s\n", arr);
	return 0;
}