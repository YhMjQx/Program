#include<stdio.h>
void test1(int p[3][5])//如果要省略[]中的数字，只能省略第一个[]中的数字，第二个[]中的数字必须保留
{}
void test2(int(*p)[5])//既然二维数组首元素是一行一维数组，那么就用一个指向数组的指针来接收即可
{}
//错误的是void tset(int **p) - error
int main()
{
	int arr[3][5] = { 0 };
	test1(arr);
	test2(arr);
	/*	二级指针为什么不能用来接收二维数组的地址，答案一：用不上，二级指针需要取地址两次，但是二维数组我只需要取一次地址便能得到二维数组首元素的地址
	答案二：不被允许,可以根据二级指针取两次地址得知，此时p=&arr[0][0],那么*p得到的是一个数字，如果再接引用，那么就是一个违法操作，根本不被允许
	答案三：二级指针是指向一级指针的，即二级指针存放的是一级指针的地址，那么二级指针+1移动的是一个一级指针的大小，而一个一级指针的大小就是4个字节
	          也就是说二级指针+1移动4个字节，但是二位数组首元素+1，移动的的大小却是一个数组的大小，不匹配，所以不行*/
	return 0;
}