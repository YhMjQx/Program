#include<stdio.h>
int main()
{
	int num = 0;
	int count = 0;
	printf("请输入您想要查找的数字:>");
	scanf("%d", &num);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
		{
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
/*	int num = 0;
	int count = 0;
	printf("请输入您想要查找的数字:>");
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 1)//如果等于1，也就是说被我们找到了这个1，因为我们不是要计算1的个数嘛
		{
			count++;
			num = num / 2;
		}
	}
	printf("%d\n", count);
	这段代码不够完美，有缺陷。
*/