#include<stdio.h>
int is_prime(int n)
{
	int j = 0;
	for (j = 2; j < n; j++)
	{
		
		if (0 == n%j)	
			return 0;//return 0的执行情况为直接停止函数，而break的执行情况为终止循环
	}
	//只有for循环条件不成立才会来到这
	return 1;
}
int main()
{
	int i = 0; 
	for (i = 100; i <= 200; i++)
	{
		if (is_prime(i) == 1)
		
			printf("%d ", i);
     }
	return 0;
}
