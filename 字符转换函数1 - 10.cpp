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

	//���ִ��벻�ܷ���һ���ã�����ͻ�������⣬���ִ��벻������

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
