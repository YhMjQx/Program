#include<stdio.h>
#include<string.h>
void Fan_string(char arr[])
{
	char tmp=arr[0];//第一步，将首元素放空 
	int len=strlen(arr); 
	arr[0]=arr[len-1];//第二步，将最后一个元素放在首元素的地方 
	arr[len-1]='\0';//第三步，放置\0控制 
	if(strlen(arr+1)>=2)//第四步，给定递归的限制，并逆序中间剩下的字符串 
		Fan_string(arr+1);
	arr[len-1]=tmp;//最后一步，将首元素放在最后一个元素的地方 
}
int main() 
{
	char arr[]="YhMjQx";
	Fan_string(arr);
	printf("%s\n",arr);	
	return 0;
 } 
