#include<stdio.h>
int main()
{
	int arr[3][3] = { { 3, 9 }, { 3, 9 } };//可以省略行数，但一定不能省略列数
	int i = 0;
	for (i = 0; i < 3; i++)
	{ 
		int j = 0;
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
			printf("&arr[%d][%d]=%p    ", i, j, &arr[i][j]);
		}
		printf("\n");
	}
	return 0;

}