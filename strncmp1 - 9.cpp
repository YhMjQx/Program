#include<stdio.h>
#include<string.h>
int main()
{
	const char* arr1 = "YMQ";
	const char* arr2 = "YMQ&&HJX";
	printf("%d\n", strncmp(arr1, arr2, 3));
	printf("%d\n", strncmp(arr1, arr2, 4));
	return 0;
}