#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));//注意char的取值范围（0,1,2...127,-128,-127...-1,0）,而与此同时，strlen找到\0（0）便停下了
	return 0;
}