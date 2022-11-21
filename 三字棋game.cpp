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
	//����--����߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	Initboard(board,ROW,COL);//����������麯������Ϸ����ش��룬��h�ļ�����������c�ļ���ʵ��
	//��ӡ����
	Displayboard(board,ROW,COL);
    //���ڿ�ʼ
	while (1)
	{
		//�������
		Playmove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		Computermove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("����������ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������ȷ����ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}