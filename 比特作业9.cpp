#include<stdio.h>
int main()
{
	int i=0;
	for(i=1;i<=9;i++)
	{
		int j=0;
		for(j=1;j<=i;j++)//ע�⣬������j<=i������j<=9 
		{
		printf("%d*%d=%-2d\t",j,i,i*j);
		}
		printf("\n");
	}
	return 0;
	
}
