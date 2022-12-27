#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul (int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//需要一个数组，来存放四个函数的地址
	int(* parr[4])(int, int) = {Add,Sub,Mul,Div};
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](3, 9));
	}
	//实战演练
	char* my_strcpy(char* dest, const char* src);
	//写一个函数指针pf，指向my_strcpy
	char* (*pf)(char*,const char*);
	//写一个函数指针数组pfArr，能够存放四个my_strcpy函数的地址
	char* (*pfArr[4])(char*,const char*);
	return 0;
}
