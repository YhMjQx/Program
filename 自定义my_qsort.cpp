#include<stdio.h>
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
int cmp_struct_name(const void* e1,const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int cmp_struct_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}
void Swap(char* m_q1, char*m_q2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *m_q1;
		*m_q1 = *m_q2;
		*m_q2 = tmp;
		m_q1++;
		m_q2++;
	}
}
void my_qsort(void* base,int sz,int width,int (*cmp)(const void* e1,const void* e2) )
{
	int i = 0;
	//确定比较的趟数
	for (i = 0; i < sz - 1; i++)
	{
		//确定每趟比较的对数
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)//void*的指针是不能随便相加减的，所以需要转换为char*类型的指针
			{
				//交换
				Swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
			}
		}
	}
	printf("\n");
}
void test1()
{
	int arr[10] = { 1 , 3 , 5 , 7 , 9 , 0 , 2 , 4 , 6 , 8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	struct stu s[3] = { { "yangmingqiang", 18.1 }, { "hujiaxin", 18.5 }, { "xiaohuyang", 0.0 } };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_struct_name);
	int i = 0;
	printf("%s\n", s[0].name);
	printf("%s\n", s[1].name);
	printf("%s\n", s[2].name);
}
void test3()
{
	struct stu s[3] = { { "yangmingqiang", 18.1 }, { "hujiaxin", 18.5 }, { "xiaohuyang", 0.0 } };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_struct_age);
	int i = 0;
	printf("%f\n", s[0].age);
	printf("%f\n", s[1].age);
	printf("%f\n", s[2].age);
}
int main()
{
	test1();
	test2();
	test3();
	return 0;
}