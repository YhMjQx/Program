#include<stdio.h>
int sum(int a)
{
	int c = 0;
	static int b = 3;//static修饰局部变量，改变局部变量的生命周期，使得b改变后能突破{}而不改变，从而继续使用
	c += 1;//但c并没有static修饰，于是第二次的c依旧是0
	b += 2;//第一次b变为5，然后又变为7...
	return(a + b + c);
}
int main()
{
	int a = 2;//这个a只能在这个{}中使用
	int i = 0;
	i++;
	for (i = 1; i < 5; i++)
	{
		printf("%d\n", sum(a));
	}
	return 0;
}