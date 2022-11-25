#include<stdio.h>
#include<math.h> 
int main()
{
	int i; //需要判断的数
	int j; //除数
	int flag=1; //素数标志位
	for (i = 100; i < 201; i++)
	{
		flag = 1;
		for (j = 2; j < sqrt(i) + 1; j++)
		{
			if (i % j == 0)
				flag = 0;//如果不是素数，我就让flag为0 
		}
		if (flag == 1)//如果是素数，我就让其判断素数是不是1，由于不是素数的情况下上面已经将flag变为0了，所以下面的代码就排除了不是素数的情况 
			printf("素数：%d\n", i);
	}
	return 0;
}
