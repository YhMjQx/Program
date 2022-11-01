#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**************************\n");
	printf("***  1.play   0.exit  ****\n");
	printf("**************************\n");
}
//RAND_MAX        0到32767  
void game()
{
	//1.生成一个随机数
	int ret = 0;
	int guess = 0;//接收猜的数字
	ret = rand()%100+1;//生成随机数,32767太大了，取模得余数都在1到99之间，加一之后所得到的ret就在1到100之间
	//printf("%d \n", ret);
	//2.猜数字
	while (1)
	{
		printf("猜数字:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	//拿时间戳设置随机数生成的起始点
	srand((unsigned int)time(NULL));//将这个放在主函数，每次只调用一次，否则放在循环中每次都会调用
	//时间戳：当前计算机的时间-计算机的起始时间（19701.1.0:0:0）=（*****....）秒
	int input = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//猜数字游戏过程
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}