#include<stdio.h> 
int main()
{
	float p;
	int q;
	float m;
	printf("请输入苹果的价格和数量\n");
	scanf("%f %d",&p,&q);
	if(q>=1&&q<=8)
	{
		m=p*0.85*q;
	}
	else if(q>8&&q<=100)
	{
		m=p*0.7*q;
	}
	else(q>=100);
	{
		m=p*0.5*q;
	}
	printf("%f",m);
	return 0; 
}

