#include<stdio.h>
int main()
{
	int x,y,z,max;
	printf("������x��y��z��\n");
	scanf("%d %d %d",&x,&y,&z);
	if(x>y)
	{
		if(x>z)
		   max=x;
		else
		   max=z;
	}
	else if(y>z)
	{
		if(y>x)
		   max=y;
		else
		   max=x;
    } 
    else
    {
    	if(x>y)
    	max=x;
    	else
    	max=y;
	}
    printf("���ֵ=%d",max);
    return 0;

 } 
