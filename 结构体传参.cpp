#include<stdio.h>
typedef struct stu//typedef在这里的作用就是重命名
{
	char name[20];
	char id[8];
	char sex[5];
	char age[4];
}stu;
void print1(stu s)
{
	printf("姓名: %s\n", s.name);
	printf("出生年月:%s\n", s.id);
	printf("性别: %s\n", s.sex);
	printf("年龄:%s\n", s.age);
}
void print2(stu* ps)
{
	printf("姓名: %s\n", ps->name);
	printf("出生年月:%s\n", ps->id );
	printf("性别: %s\n", ps->sex );
	printf("年龄:%s\n", ps->age );
}
int main()
{
	printf("接下来有请这对新人登场！！！\n");
	printf("首先介绍女方信息：\n");
	stu H = { "胡佳欣", "040711", "女", "18" };
	print1(H);
	printf("接下来介绍男方信息：\n");
	stu Y = { "杨明强", "041113", "男", "18" };
	print2(&Y);
	return 0;
}