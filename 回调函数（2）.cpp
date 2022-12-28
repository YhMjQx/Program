#include<stdio.h>
void Print(char* str)
{
	printf("%s\n", str);
}
void test(void(*pf)(char*))
{
	printf("Let's toast:");
	(*pf)("YhMjQx");
	//pf("YhMjQx");
}
int main()
{
	test(Print);
	return 0;

}