#include<stdio.h>
#pragma pack(1)//修改默认对齐数为1
struct H
{
	char a;
	int b;
};
#pragma pack()//取消设置的对齐数
struct Y
{
	char a;
	int b;
};
int main()
{
	//单纯的计算结构体的大小的时候，定义结构体变量可要可不要,要的时候就就计算变量的大小即可，不要的时候直接计算结构体的大小即可
	//struct H s1 = { 0 };
	printf("%d\n", sizeof(H));//定义了结构体变量之后可写作为printf("%d\n", sizeof(s1));
	//struct Y s2 = { 0 };
	printf("%d\n", sizeof(Y));//定义了结构体变量之后可写作为printf("%d\n", sizeof(s2));
	return 0;
}