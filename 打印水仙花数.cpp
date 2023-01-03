#include<stdio.h>
#include<math.h>
int main()
{ 
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//判断一个数是否为水仙花数
		//1.计算这个数的位数
		int n = 1;
		int sum = 0;
		int tmp = i;
		while (tmp /= 10)
		{
			n++;
		}
		//2.计算这个数的每位数的n次方之和
		tmp = i;
		while (tmp)
		{
			sum += pow((float)(tmp % 10), n);
			tmp /= 10;
		}
		//比较i和sum两个数
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}