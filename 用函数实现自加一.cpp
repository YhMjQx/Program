#include<stdio.h>
void Add(int* p)//int Add(int* p)
{				//{
	(*p)++;		//(*p)++;
				//return 1;
}				//}
int main()
{//要想通过外部自定义函数来改变主函数内部元素的值，应该通过传址的形式
	int num = 0;
	Add(&num);
	printf("%d ", num);
	Add(&num);
	printf("%d ", num);
	Add(&num);
	printf("%d ", num);
	return 0;
}