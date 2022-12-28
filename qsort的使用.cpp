#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	char name[20];
	float age;
};
int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test1()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cam_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}
void test2()
{
	float f[] = { 5.0, 2.0, 1.0, 3., 9.0 };
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cam_float);
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%f ", f[j]);
	}
	printf("\n");
}

int cmp_s_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}
void test3()
{
	struct stu s[3] = { {"yangmingqiang",18.1}, {"hujiaixn",18.5}, {"xiaohuyang",0.0} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_s_name);
	printf("%s ", s[0].name);
	printf("%s ", s[1].name);
	printf("%s ", s[2].name);
	printf("\n");
}

int cmp_s_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
void test4()
{
	struct stu s[3] = { { "yangmingqiang", 18 }, { "hujiaixn", 19 }, { "xiaohuyang", 0 } };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_s_age);
	printf("%f ", s[0].age);
	printf("%f ", s[1].age);
	printf("%f ", s[2].age);
	printf("\n");
}
int main()
{
/*	int a = 10;
	void* p = &a;
	void* 类型的指针 可以接收任意类型的地质
	void* 类型的指针 不能进行解引用操作
	void* 类型的指针 不能进行+-整数的操作*/
	test1();
	test2();
	test3();
	test4();
	return 0;
}