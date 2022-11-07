#include<stdio.h>
int is_leap_year(int x)
{
	if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
		return 1;
	else
		return 0;
}

int main()
{
	int year = 0;
	for (year = 1000; year <= 2022; year++)
	{
		if (is_leap_year(year) == 1)
			printf("%d ", year);
	}
	return 0;
}