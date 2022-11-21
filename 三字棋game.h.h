#define ROW 3
#define COL 3
//函数的声明
#include<stdlib.h>
#include<time.h>
void Initboard(char board[ROW] [COL], int row, int col);
void Displayboard(char board[ROW] [COL],int row, int col);
void Playmove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
//告诉我们四种游戏状态
//玩家赢，返回'*'表示玩家赢  
//电脑赢，返回'#'表示电脑赢
//平局，返回'Q'
//继续，返回'C'
char Iswin(char board[ROW][COL], int row, int col);
