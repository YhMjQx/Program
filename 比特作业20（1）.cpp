#include<stdio.h>
int Num_bits_one(unsigned int x)//Ϊ�˷�ֹ-1��Ӱ�죬���Ǽ���unsigned 
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
	printf("��������Ҫ�鿴�����֣�");
	scanf("%d",&a);
	count = Num_bits_one(a);
	printf("��������1�ĸ���Ϊ��%d\n",count);
	return 0;
	
 } 
