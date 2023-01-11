#include<stdio.h>
struct s1
{
	char a1;
	int b1;
	char a2;
};
struct s2
{
	char a1;
	char a2;
	int b1;
};
int main()
{
	printf("%d\n", sizeof(s1));
	printf("%d\n", sizeof(s2));
	return 0;
}