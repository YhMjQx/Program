#include<stdio.h>
int main()
{
	int i = 0;
	while (i <= 10)
	{
		i++;
		if (i == 5)
			continue;//不再执行i=5这次循环下面的内容结果为1 2 3 4 6 7 8 9 10 11,直接跳转到while判断这一行 
		printf("%d ", i);
	}
	return 0;
}
//continue：终止本次循环continue后面的代码，直接跳转到while判断部分，进行下一次循环
