#include<stdio.h>
int Digitsum(int x)
{
	if(x>9)
	{
		return Digitsum(x/10)+x%10;
	}
	else
	{
		return x;
	}
}
int main()
{
	unsigned int a=0;
	printf("����������Ҫ��������֣�"); 
	scanf("%d",&a);
	int ret=Digitsum(a); 
	printf("%d",ret);
	return 0; 
} 
