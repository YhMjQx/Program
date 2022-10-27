#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0, j = 0; j = 0; i++, j++)//注意，我们for循环当中中间的部分是判断语句，但这里是赋值语句，给j赋值0，也就是说，这是假，固该循环不进行
		j++;
	return 0;
}