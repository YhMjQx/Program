#include<stdio.h>
//杨氏矩阵：一个数字矩阵，矩阵的每一行从左到右是递增的，矩阵从上到下也是递增的
//编写程序，在这样的矩阵中查找一个数字的存在
int Findnum(int arr[3][3], int k, int* px, int* py)
{
	//确定右上角数字的下标
	int x = 0; 
	int y = *py - 1;
	while ((x<=*px-1)&&(y>=0))
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	//找不到
	return 0;
}
int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 0;
	//这里的x，y代表的是行，列数
	int x = 3;
	int y = 3;
	printf("请输入您想要查找的数字：");
	scanf("%d", &k);
	int ret = Findnum(arr, k, &x, &y);//传参时，给数字取地址，叫做返回型参数，即在函数内部改变变量
	if (ret == 1)
	{
		printf("找到了！该数字的下标是%d %d\n", x, y);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}