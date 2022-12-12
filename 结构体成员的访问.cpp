#include<stdio.h>
struct S
{
	int a;
	char c;
	char arr[20];
	double d;
};
struct T
{
	char ch[10];
	struct S s;
	char* pc;
};
int main()
{
	char arr[] = "yshysh";
	struct T t = { "YhMjQx", {39,'y',"hello YhMjQx",13.14}, arr };
	printf("%s\n", t.ch);
	printf("%s\n", t.s.arr );
	printf("%lf\n", t.s.d);
	printf("%s\n", t.pc);
	return 0;
}