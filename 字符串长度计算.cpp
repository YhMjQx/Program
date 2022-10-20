
#include<string.h>//引用头文件，用来使用strlen函数。
#include<stdio.h>
int main()
{//双引号引的是字符串，单引号引的是单个字符。
	char arr1[] = "YhMjQx";//字符串中自带\0，他是字符串结束的标志，数值等于0。
	char arr2[] = { 'Y', 'h', 'M', 'j', 'Q', 'x', '\0' };//而单个输入字符并不带有\0，故需在最后加上\0或者0。
	printf("%d\n", strlen(arr1));//strlen-string length用来计算字符串的长度。
	printf("%d\n", strlen(arr2));
	return 0;	
}