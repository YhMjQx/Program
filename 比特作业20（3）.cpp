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
//x=12&13   		1100     ��λ��һ�� 
//x=11      		1011
//x=(12&13)&11  	1000     ��λ������ 
//x=10				0111
//x=((12&13)&11)&10 0000     ��λ������ 
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
