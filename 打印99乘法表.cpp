#include<stdio.h>
int main()
{
	int i = 0;
	for (i = 1; i <= 9; i++)//确定打印9行
	{
		int j = 1;
		for (j = 1; j <= i; j++)//确定打印9列
		{
			printf("%d*%d= %-2d\t", i, j, i*j);//%-2d是左对齐，%2d是右对齐,\t是水平制表符
		}
		printf("\n");//每一大组循环完了之后进行一个换行操作
	}
	return 0;
}