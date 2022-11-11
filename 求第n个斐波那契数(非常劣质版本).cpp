#include<stdio.h>
//1 1 2 3 5 8 13 21 34 55......
long Fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return  Fib(n - 1) + Fib(n - 2);
	}
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈënµÄÖµ:>");
	scanf("%d", &n);
	printf("Fib(n)=%d\n", Fib(n));

	return 0;

}