#include<stdio.h>
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;//1 1 2 3 5 8 13 21 34 55...
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈënµÄÖµ:>");
	scanf("%d", &n);
	printf("Fib=%d\n", Fib(n));
	return 0;
}