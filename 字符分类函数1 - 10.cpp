#include<stdio.h>
#include<ctype.h>
int mian()
{
	iscntrl;//判断是否为控制字符
	isspace;//判断是否为空白字符：空格，换页'\f',换行'\n',回车'\r',水平制表符'\t',垂直制表符'\v'
	isdigit;//判断是否为十进制数字 0 - 9
	isxdigit;//判断是否为十六进制数字，包括所有十进制数字，小写字母a-f,大写字母A-F
	islower;//判断是否为小写字母a-z
	isupper;//判断是否为大写字母A-Z
	isalpha;//判断是否为字母a-z或A-Z
	isalnum;//判断是否为字母或数字a-z，A-Z，0-9
	ispunct;//判断是否为标点符号，任何不属于数字或者字母的图形字符（可打印）
	isgraph;//判断是否为任何图形字符
	isprint;//判断是否为任何可打印字符，包括可打印字符和空白字符
	//一般情况下，符合条件返回一个不为0的数，若不符合条件，则返回0
	return 0;
}