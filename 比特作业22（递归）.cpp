#include<stdio.h>
#include<string.h>
void Fan_string(char arr[])
{
	char tmp=arr[0];//��һ��������Ԫ�طſ� 
	int len=strlen(arr); 
	arr[0]=arr[len-1];//�ڶ����������һ��Ԫ�ط�����Ԫ�صĵط� 
	arr[len-1]='\0';//������������\0���� 
	if(strlen(arr+1)>=2)//���Ĳ��������ݹ�����ƣ��������м�ʣ�µ��ַ��� 
		Fan_string(arr+1);
	arr[len-1]=tmp;//���һ��������Ԫ�ط������һ��Ԫ�صĵط� 
}
int main() 
{
	char arr[]="YhMjQx";
	Fan_string(arr);
	printf("%s\n",arr);	
	return 0;
 } 
