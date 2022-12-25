#include<stdio.h>
int  my_strlen(char* arr)
{
	int count=0;
	while(*arr!='\0')
	{
		arr++;
		count++;
	}
	return count;
}
int main()
{
	char arr[]="YhMjQx";
	printf("%d\n",my_strlen(arr));
	return 0;
 } 
