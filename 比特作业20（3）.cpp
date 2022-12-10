#include<stdio.h>
int Num_bits_one( int x)
{
	int count=0;
	while(x)
	{
		x=x&(x-1);
		count++;
	}
	return count;
}
//x=13      		1101
//x=12      		1100
//x=12&13   		1100     按位与一次 
//x=11      		1011
//x=(12&13)&11  	1000     按位与两次 
//x=10				0111
//x=((12&13)&11)&10 0000     按位与三次 
int main()
{
	int a=0;
	int count=0;
	printf("请输入想要查看的数字：");
	scanf("%d",&a);
	count = Num_bits_one(a);
	printf("该数字中1的个数为：%d\n",count);
	return 0;
 } 
