#include<stdio.h>
int main()
{
int i=0;
int count=0; 
for(i=100;i<=200;i++)
{
	int j=0;
	for(j=2;j<=i-1;j++)
	{
		if(0==i%j)
		{
		break;//����i��ʱ�ܱ�һ��2��i-1֮����������������i��������������ӡ���������ѭ�� 
		}
	}
	if(i==j)//��Ȼ��ʱi�ᱻ��������ô������֤һ�����i��j�ǲ�����ȵģ����������Ǿ����������ʹ�ӡ 
	{
		printf("%d ",i);
		count++;
	 } 
}
printf("\nһ����%d������\n",count); 

	return 0;
	
} 
