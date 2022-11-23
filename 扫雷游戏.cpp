#define _CRT_SECURE_NO_WARNINGS 1
#include"扫雷游戏.h"
#include<stdio.h>
void menu()
{
	printf("************************\n");
	printf("****     1.play     ****\n");
	printf("****     0.exit     ****\n");
	printf("************************\n");
}
void game()
{
	printf("扫雷\n");
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');
	//打印棋盘
	Displayboard(mine,ROW,COL);//因为我只需用将9*9的格子打印出来即可，所以这里传的是ROW，COL
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入选项:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入正确选项\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}