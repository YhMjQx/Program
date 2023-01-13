#include<stdio.h>
union HY
{
	char h;
	int y;
};
union H
{
	int h;
	char arr[5];
};
//该联合体的最大对齐数是4，其总大小，首先5个字节就足够了，但是因为5个字节不是最大对齐数的整数倍，于是对齐之后总大小就变成了8
int main()
{
	union HY hy;
	printf("%d\n", sizeof(hy));
	printf("%p\n", &hy);
	printf("%p\n", &hy.h);
	printf("%p\n", &hy.y);
	//由打印结果可知，联合体内部的成员变量共用一块空间，因此同一时刻 h，y不能同时存在并更改，改变其中任何一个，另一个都会发生改变 
	/*联合体的大小至少是最大成员的大小
	当最大成员的大小不是最大对齐数的整数倍的时候，联合体的大小就要对齐到最大对齐数的最大整数倍*/
	union H y;
	printf("%d\n", sizeof(y));
	return 0;
}