#include<stdio.h>
void Swap(int *a,int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int a=0;
	int b=0;
	printf("请输入想交换的两个数字a,b:>");
	scanf("%d %d",&a,&b);
	Swap(&a,&b);
	printf("a=%d b=%d\n",a,b);
	int c=1;
	int d=2;
	c=c^d;
	d=c^d;
	c=c^d;
	printf("c=%d d=%d\n",c,d);
	return 0;
}
