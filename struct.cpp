#include<stdio.h>
#include<stdio.h> //strcpy(a.name,"胡杨");     用这样的代码，我就能把name由“胡杨爱情史”变为“胡杨”
struct Book//用struct可以自己设计一个结构体类型，struct叫做结构体关键字，其实类似于构建一个函数
{
	char name[20];
	long long price;//8个字节，因此价格就是个八位数
};//注意，这里的分号可不能丢!!!
int main()//利用结构体类型，创建一个结构体变量
{
	struct Book a = { "胡杨爱情史\n", 39393939 };
	printf("书名：%s", a.name);//第一种打印方式    .是一个操作符，在结构体变量当中用来找到自己所需的成员
	printf("价格：%d\n", a.price);
	struct Book* pa = &a;
	printf("书名：%s\n", (*pa).name);//注意，用这种方法解引用一定需要加小括号，第二种打印方式
	printf("价格：%d\n", (*pa).price );
	printf("书名：%s\n", pa->name);//第三种打印方式，结构体指针->成员
	printf("价格：%d\n", pa->price);
	return 0;
}