#include<stdio.h>
int main()
{
	int a=0;
	printf("请输入a的值:");
	scanf("%d",&a); 
	if(a%2==1)
	printf("a是奇数\n"); 
	else
	printf("a不是奇数\n");
	int b=1;
	while(b<=98)
	{
		b+=2;
		printf("1~100内的奇数b=%d \n",b);
		
	}

	
	return 0;
	
}
