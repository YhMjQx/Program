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
	//��Ҫһ�����飬������ĸ������ĵ�ַ
	int(* parr[4])(int, int) = {Add,Sub,Mul,Div};
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", parr[i](3, 9));
	}
	//ʵս����
	char* my_strcpy(char* dest, const char* src);
	//дһ������ָ��pf��ָ��my_strcpy
	char* (*pf)(char*,const char*);
	//дһ������ָ������pfArr���ܹ�����ĸ�my_strcpy�����ĵ�ַ
	char* (*pfArr[4])(char*,const char*);
	return 0;
}
