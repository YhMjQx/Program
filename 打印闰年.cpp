#include<stdio.h>
int main()
{
	int year = 0;
	int count = 0;
	for (year = 1000; year <= 2022; year++)
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			printf("%d ", year);
			count++;
		}
		else if(year % 400 == 0)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\n一共有%d年", count);
	return 0;

}