#include<stdio.h>
int main()
{
	int a=0;
	printf("������a��ֵ:");
	scanf("%d",&a); 
	if(a%2==1)
	printf("a������\n"); 
	else
	printf("a��������\n");
	int b=1;
	while(b<=98)
	{
		b+=2;
		printf("1~100�ڵ�����b=%d \n",b);
		
	}

	
	return 0;
	
}
