#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1==*str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
	//	return 1;
	//else
	//	return -1;
		return (*str1 - *str2);
}
int main()
{
	char ch1[] = "YMQ";
	char ch2[] = "HJX";
	int ret = my_strcmp(ch1, ch2);
	printf("%d\n", ret);
	return 0;
}