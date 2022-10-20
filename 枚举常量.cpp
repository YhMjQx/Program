#include<stdio.h>
enum Sex//枚举-一一列举，其关键为enum
{
	MALE,//注意这里的逗号
	FEMALE,//注意这里的逗号
	SECRET
	//这三个量为枚举常量，是不能改的。
};//这里的分号很重要，莫忘。
int main()
{
	//枚举常量不能改，但是在这下面的主函数中却能通过“enum Sex sex=SECRET;color=FEMALE;”进行改变.
	printf("%d\n", MALE);//0
	printf("%d\n", FEMALE);//1
	printf("%d\n", SECRET);//2
	return 0;
}