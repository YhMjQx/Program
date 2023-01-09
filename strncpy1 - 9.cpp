#include<stdio.h>
#include<string.h>
int main()
{
	char ch1[] = "YhMjQx";
	char ch2[] = "YMQ";
	strncpy(ch1, ch2, 1);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 2);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 3);
	printf("%s\n", ch1);
	strncpy(ch1, ch2, 4);
	//由此可见，我所要覆盖的字节数也可以大于我的source字符串
	//此时将会把原字符串的所有包括'\0'覆盖到目标空间，此时就相当于strcpy
	//同时我所需要的长度如果源字符串不够的话就会给我补'\0'直到给我补够所规定的字节数
	printf("%s\n", ch1);
	return 0;
}