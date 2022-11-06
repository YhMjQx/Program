#include<stdio.h>
#include<string.h>
//递归的两个条件：
//存在限制条件，当满足这个限制条件之后，递归便不再继续
//每次递归调用之后越来越接近这个限制条件
int print(int n)
{
	if (n > 9)//这里必须要有条件限制，否则就会死循环直到栈溢出
	{
		print(n / 10);//这里的n也必须要除以10，使n不停的变小，如果n不变，那么也会死循环直到栈溢出
	}
	return printf("%d ", n % 10);//既然要分开打印，那么这里一定是"%d "才行
}

int main()
{
	unsigned int num = 0;
	printf("请输入数字串:>");
	scanf("%d", &num);//既然要分开打印，那么你输入时就应该合在一起输入，那么这里就只能"%d"
	print(num);
	return 0;
}