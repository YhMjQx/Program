#include<stdio.h>
int Separatenum(int n)
{
	if(n>9)
	{
		Separatenum(n/10);
	}
	return printf("%d ",n%10);
}
int main() 
{
	int n=0;
	printf("ÇëÊäÈëÒ»´®Êı×Ö:>");
	scanf("%d",&n);
	Separatenum(n);
	return 0;
} 
