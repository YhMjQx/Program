#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x^y;
}
void menu()
{
	printf("***********************\n");
	printf("** 1.Add       2.Sub **\n");
	printf("** 3.Mul       4.Div **\n");
	printf("** 5.Xor       0.exit**\n");
	printf("***********************\n");
}
void Calc(int(*pfarr)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pfarr(x, y));
}
int main()
{
	//回调函数就是一个通过函数指针调用的函数，依旧用转移表（计算器）来做演示
	int input = 0;
	do
	{
		menu();
		printf("请选择要进行的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出程序\n");
		default:
			break;
		}
	} while (input);
	return 0;
}