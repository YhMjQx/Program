#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	int arr[10] = { 0 };
	int (*p)[10]=&arr;//数组指针
	int(*pf)(int, int);//函数指针
	int(*pfArr[4])(int, int);//函数指针数组
	int(*(*ppfArr)[4])(int, int)=&pfArr;//指向函数指针数组的指针
	//pfArr是一个函数指针数组，指向的数组有4个元素，每个元素为int
	//ppfArr是一个数组指针，他指向的数组有4个元素
	//指向的数组的每个元素的类型是函数指针int(*)(int, int)
	return 0;
}