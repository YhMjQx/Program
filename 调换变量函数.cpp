#include<stdio.h>
void Swap1(int x, int y)//void表示没有返回值
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}
void Swap2(int* px, int* py)//int*该类型所得为地址，因此，在下方的主函数中我调用函数时应给出地址，而不是变量
{
	int tmp = 0;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
int main()
{
	int a = 10;
	int b = 20;
	printf("a=%d b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	int c = 10;
	int d = 20;
	printf("c=%d d=%d\n", c, d);
	Swap1(c, d);
	printf("c=%d d=%d\n", c, d);
	int e = 10;
	int f = 20;
	printf("e=%d f=%d\n", e, f);
	Swap2(&e, &f);//&e传给int* pe,&f传给int* pf
	printf("e=%d f=%d\n", e, f);
	return 0;
}