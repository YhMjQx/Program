#include<stdio.h>
int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++)//判断素数的方法，试除法，即产生2到i-1的数并利用
	{
		int j = 0;
		for (j = 2; j < i; j++)//优解：j<=sqrt(i)或者把sqrt(i)变成i/2
		{
			if (0 == i%j)//这才是我要被循环的循环体,因此放进这个for循环中
			{
				break;//因为此时i能被j整除，固这个i不是素数，不打印
			}	
		}
		//为什么会突然来到这呢，你想啊，break起作用了是不是需要直接跳出这个for循环
		if (i == j)//优解：J>sqrt(i)或者把sqrt(i)变成i/2
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("\n一共有%d个素数 \n", count);
	return 0;

}
