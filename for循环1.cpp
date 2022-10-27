#include<stdio.h>
int main()
{
	int i = 0;
	for (i = 0; i <= 10; i++)//for(变量初始化;变量判断条件;变量调整部分)
	{
		printf("%d ", i);
	}
	for (;;)//这种情况就死循环了，虽说for循环中的三个部分都可以省略，但是，如果将判断部分省略掉，则判断恒为正，固会一直执行该循环
	{
		printf("胡杨\n");
	}
	return 0;
}