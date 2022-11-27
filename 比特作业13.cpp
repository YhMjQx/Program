#include<stdio.h>
int strlen(char *arr)
{
	int count=0;
	while(*arr!='\0')
	{
		count++;
		*arr++;
	}
	return count;
}
int main()
{
	char arr[]="YhMjQx1314";
	printf("%d\n",strlen(arr));
	return 0;
 } 
