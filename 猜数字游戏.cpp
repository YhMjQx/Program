#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**************************\n");
	printf("***  1.play   0.exit  ****\n");
	printf("**************************\n");
}
//RAND_MAX        0��32767  
void game()
{
	//1.����һ�������
	int ret = 0;
	int guess = 0;//���ղµ�����
	ret = rand()%100+1;//���������,32767̫���ˣ�ȡģ����������1��99֮�䣬��һ֮�����õ���ret����1��100֮��
	//printf("%d \n", ret);
	//2.������
	while (1)
	{
		printf("������:>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
}
int main()
{
	//��ʱ���������������ɵ���ʼ��
	srand((unsigned int)time(NULL));//�����������������ÿ��ֻ����һ�Σ��������ѭ����ÿ�ζ������
	//ʱ�������ǰ�������ʱ��-���������ʼʱ�䣨19701.1.0:0:0��=��*****....����
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}