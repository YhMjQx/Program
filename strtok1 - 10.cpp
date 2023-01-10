#include<stdio.h>
#include<string.h>
int main()
{
	char arr[] = "YMQ2YXH2YF2ymq2hjx";
	char* p = "2";
	char tmp[] = "YMQ2YXH2YF2ymq2hjx";
	//用for循环的时候，最后一次的确返回了NULL但是由于判断条件不成立，于是便没有打印
	for (char* ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	//char* strtok(char* str,const char* sep)
	//1.第一个参数指定一个字符串，它包含了0个或者多个sep的分隔符
	//2.strtok函数找到str中下一个分隔符的位置，并将其改为\0作为结尾，同时返回指向该分隔符之前的那一段字符串的指针
	//3.strtok函数的第一个参数不为NULL，函数找到str中的的一个分隔符标记，改为\0并保存该位置，
	//4.strtok函数的第一个参数为NULL，函数将在同一个字符串中从之前最后一次做的标记的位置开始寻找分隔符，找到后的操作同上
	//5.如果字符串中不含有更多的分隔符标记，则返回NULL，这也正是为什么用while循环最后会打印一个NULL的原因

	//找到第一个分隔符，在这里也就是2，并将此分隔符改为\0，并返回指向这个串的地址
	//在这里举例子：
	//YMQ2YXH2YF2ymq2hjx，找到第一个2，改为\0，然后返回指向第一个Y的指针地址

	//char* ret=strtok(tmp, p);
	//printf("%s\n", ret);
	//while (ret != NULL)
	//{
	//	ret = strtok(NULL, p);
	//	printf("%s\n", ret);
	//}
	return 0;
}