#include<stdio.h>
//结构体的声明
//描述一个学生的一些数据：名字，年龄，电话，性别
//strcut--结构体关键字     stu--结构体标签      struct stu--结构体类型
struct stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
};
int main()
{
	struct stu s;
	return 0;

}