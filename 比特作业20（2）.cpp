#include<stdio.h>
int Num_bits_one( int x)
{
	int count=0;
	int i=0;
	for(i=0;i<32;i++)
	{
		 if(((x>>i)&1)==1)
		 {
		 	count++;
		 }
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
