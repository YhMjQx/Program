#include<stdio.h>
int main()
{
    int a=20;
    int b=40;
    int r=0;
    while(a%b)
    {
    	r=a%b;
    	a=b;
    	b=r;
	}

printf("%d",r);
return 0;
}
