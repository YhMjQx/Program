#define ROW 3
#define COL 3
//����������
#include<stdlib.h>
#include<time.h>
void Initboard(char board[ROW] [COL], int row, int col);
void Displayboard(char board[ROW] [COL],int row, int col);
void Playmove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
//��������������Ϸ״̬
//���Ӯ������'*'��ʾ���Ӯ  
//����Ӯ������'#'��ʾ����Ӯ
//ƽ�֣�����'Q'
//����������'C'
char Iswin(char board[ROW][COL], int row, int col);
