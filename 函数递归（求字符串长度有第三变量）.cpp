#include<stdio.h>
#include<string.h>
int My_strlen(char* str)//str当中存储的是arr第一个元素的地址
{
	int count = 0;
	while (*str != '\0')//需要循环才能实现，这个是字符不等于\0
	{
		//他这里使用str来伴随count，这样循环才能实现，count是要随着str的++而++的
		count++;
		str++;//这里是地址加一，才能使判断进入下一个字符，不是解引用之后加一
	}
	return count;
}
int main()
{
	char arr[] = "hy39";//h y 3 9 \0
	printf("%d\n", My_strlen(arr));
	return 0;
}