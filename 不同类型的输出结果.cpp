#include<stdio.h>
int main()
{
	char a = -1;
	//-1的  10000000000000000000000000000001
	//      11111111111111111111111111111110
	//      111111111111111111111111
	//11111111(截断为char型)
	//11111111111111111111111111111111(整形提升)
	signed char b = -1;
	//11111111
	//11111111111111111111111111111111+
	unsigned char c = -1;
	//11111111
	//00000000000000000000000011111111
	printf("a=%d b=%d c=%d\n", a, b, c);	
	int d = -128;
	printf("%u\n", d);
	//%d——打印十进制的有符号数
	//%u——打印十进制的无符号数
	return 0;
}

