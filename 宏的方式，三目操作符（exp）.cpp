#include<stdio.h>
#define MAX(x,y) (x>y?x:y)//�ú�Ķ��巨����Ŀ���������Ա���ʹ�ú�������Ϊ�����Ƚ��鷳 
int main()
{
	int x=10;
	int y=20;
	int max=MAX(x,y);
	printf("max=%d",max);
	return 0;
 } 
