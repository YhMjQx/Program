#include<stdio.h>
int main()
{
	float x=0;
	float y=0;
	printf("ÇëÊäÈëxµÄÖµ\n");
	scanf("%f",&x);
	if(x<10){
		y=x;
	}
	
	else if(x>=10&&x<50){
		y=3*x-2;
	}

	else if(50<=x&&x<100){
		y=4*x+1;
	}
	
	else{
		y=5*x;
	}
	
	printf("y=%f",y);
	return 0;
 } 
