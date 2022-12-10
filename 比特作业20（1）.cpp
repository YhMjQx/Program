#include<stdio.h>
int Num_bits_one(unsigned int x)//为了防止-1的影响，于是加了unsigned 
{
	int count=0;
	while(x)
	{
		if(x%2==1)
		{
		count++;
		}
		x=x/2;
	}
	return count;
}
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
