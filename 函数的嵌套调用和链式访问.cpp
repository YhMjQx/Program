#include<stdio.h>
#include<string.h>
//链式访问：把一个函数的返回值作为另外一个函数的参数
int main()
{
	int HY = 39;
	printf("%d ", strlen("HY"));
	printf("%d", printf("%d", printf("%d", 43)));//打印顺序：由内向外，打印的是每一次printf的返回值，结果为4321 
	//printf("%d", 43)的返回值是打印字符的个数，即第一次打印的结果是43，那么第二次打印结果就是2，第三次打印结果是1
	return 0;
}
