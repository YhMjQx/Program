#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int i = 0;
	//char arr1[] = "MDQ2yxh";
	//while (arr1[i])
	//{
	//	if (isupper(arr1[i]));
	//	{
	//		arr1[i]=tolower(arr1[i]);
	//	}
	//	i++;
	//}
	//printf("%s\n", arr1);

	//两种代码不能放在一起用，否则就会出现问题，部分代码不起作用

	char arr2[] = "YMQ2hjx";
	while (arr2[i])
	{
		if (islower(arr2[i]))
		{
			arr2[i] = toupper(arr2[i]);
		}
		i++;
	}
	printf("%s\n", arr2);
	return 0;
}
