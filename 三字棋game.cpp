#include<stdio.h>
#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("****1.play   0.exit****\n");
	printf("***********************\n");
}
void game()
{
	char ret = 0;
	//数组--存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Initboard(board,ROW,COL);//重置这个数组函数，游戏的相关代码，在h文件中声明，在c文件中实现
	//打印棋盘
	Displayboard(board,ROW,COL);
    //下期开始
	while (1)
	{
		//玩家下棋
		Playmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//判断玩家是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		Computermove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//判断电脑是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("请输入您的选项:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请正确输入选项\n");
			break;
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}