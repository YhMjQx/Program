#define _CRT_SECURE_NO_WARNINGS 1
#include"ɨ����Ϸ.h"
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
	printf("ɨ��\n");
	//�׵���Ϣ�洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	Initboard(mine, ROWS, COLS,'0');
	Initboard(show, ROWS, COLS, '*');
	//��ӡ����
	Displayboard(mine,ROW,COL);//��Ϊ��ֻ���ý�9*9�ĸ��Ӵ�ӡ�������ɣ��������ﴫ����ROW��COL
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������������ȷѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}