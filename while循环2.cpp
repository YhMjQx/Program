#include<stdio.h>
int main()
{
	int a = 0;
	while (a <= 10)
	{
			a++;
			printf("%d ", a); //´òÓ¡1 2 3 4 5
			if (a == 5)
				break;	
	}
	return 0;
}
