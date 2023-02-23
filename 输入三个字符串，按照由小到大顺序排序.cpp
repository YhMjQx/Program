#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp_str(const void* e1,const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}
int main()
{
	char arr[3][80] = {"abcd","abce","abcf"};
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_str);
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}
//#include <stdio.h>
//#define N 5
//struct student
//{
//	long num;
//	char name[10];
//	char sex;
//	float score[3];
//};
//void print(struct student str[N]);
//int main()
//{
//	struct student str[N];
//	int a;
//	for (a = 0; a < N; a++)
//	{
//		printf("Enter the No.%d student name:\n", a + 1);
//		gets(str[a].name);
//		printf("Enter his or her num and sex and three scores:\n");
//		scanf("%ld, %c, %f, %f, %f", &str[a].num, &str[a].sex, &str[a].
//			score[0], &str[a].score[1], &str[a].score[2]);
//		while (getchar() != '\n')
//			continue;
//	}
//	print(str);
//	return 0;
//}
//void print(struct student str[])
//{
//	int a;
//	float average[N];
//	struct student *p = NULL;
//	for (a = 0, p = str; p < str + N; a++, p++)
//	{
//		printf("The No.%d student personal information:\n", a + 1);
//		printf("%ld%10s%2c %5.2f %5.2f %5.2f\n", (*p).num,
//			(*p).name, (*p).sex, (*p).score[0], (*p).score[1], (*p).score[2]);
//	}
//	for (a = 0; a < N; a++)
//	{
//		average[a] = (str[a].score[0] + str[a].score[1] + str[a].score[2]);
//		printf("The No.%d student average grades: %5.2f\n",
//			a + 1, average[a] / 3);
//	}
//}