#include<stdio.h>
#include<string.h>
//strcat(arr1, arr2); 可以将arr2追加在arr1的后面，但是该函数不能让arr1追加arr1本身
//strncat(arr1, arr1, n); 该函数同样也是字符串追加函数，还可以让arr1追加本身，只是比strcat函数多了一个字符个数的参数罢了
//strstr(arr1, arr2);该函数是用来在arr1当中找到arr2的，也就是说是一个找子串的函数,他会返回找到的子串的首字符的地址,如果没找到，就返回NULL
int Is_Round(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(str1, str2, len2);
	char* ret = strstr(str1, str2);
	if (ret==NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
int main()
{
	char arr1[39] = "YhMjQx";
	char arr2[] = "jQxYhM";
	int ret = Is_Round(arr1, arr2);
	if (ret == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}