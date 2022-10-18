#include<stdio.h>
int main()
{
	float amount;
	float money;
	printf("Enter an amount\n");
	scanf("%f",&amount);
	money=amount+amount*0.05;
	printf("With tax added%f",money);
	return 0;
}
