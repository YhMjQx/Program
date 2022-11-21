#define _CRT_SECURE_NO   _WARNINGS 1
#include<stdio.h>
#include"game.h"
//函数的实现
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0; 
	for (i = 0; i < row; i++)//将所有打印的内容以行作为单位打印
	{
		//打印一行数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j<col-1)//控制数据行的最后一列不要打印这个竖杠
			   printf('|');
		}
		printf("\n");//要等一行数据打印完了之后再换行
		if (i < row - 1)//控制最后一行不要打印分隔行
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)//控制分隔行的最后一列不要打印这个竖杠
					printf('|');
			}
			printf("\n");//等一行分隔行符号打印完了再换行
		}	
	}
}

void Playmove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋:>");
	while (1)
	{
		printf("请输入坐标:>\n");
		scanf("%d%d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row   &&   y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("改坐标已经被占用，您输入的坐标有误，请重新输入");
			}
		}
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}
//返回1表示棋盘满了，返回0表示棋盘没满
int Isfull(char board[ROW][COL], int row, int col)
{
	int i= 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < col; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//两个对角线的判断
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == Isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}