//顺序结构
//选择结构
//循环结构
#include<stdio.h>
int main()
//求出1-100内的奇数
{
	int a = 1;//如果把这里的1换成0，则求出来的结果都是偶数 
	while (a <= 100)
	{
		printf("%d ", a);
		a += 2;
	}
	return 0;
}
/*求出1-100内的奇数
while (a <= 100)
{
	if (a%2=1)
	printf("%d ", a);
	a++;
}
*/
