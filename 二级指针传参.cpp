#include<stdio.h>
void test(int **pp)//形参部分是一个二级指针，接收一级指针的地址或者二级指针
{
	printf("%d", **pp);
}
int main()
{
	int n = 39;
	int *p = &n;
	int **pp = &p;
	test(pp);
	test(&p);
	int *arr[10];//指针数组传参，该数组存放的是一级指针，也就是说传的是存放该一级指针的数组的数组名（首元素(一级指针)地址）
	test(arr);
	return 0;
}