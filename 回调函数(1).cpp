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
	printf("����������������:>");
	scanf("%d%d", &x, &y);
	printf("%d\n", pfarr(x, y));
}
int main()
{
	//�ص���������һ��ͨ������ָ����õĺ�����������ת�Ʊ���������������ʾ
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��Ҫ���еĲ���:>");
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
			printf("�˳�����\n");
		default:
			break;
		}
	} while (input);
	return 0;
}