#include<stdio.h>
int main()
{
	int day;
	scanf("%d", &day);
	switch (day)//switch����û�зֺţ������ģ����е�Ϊ���α��ʽ
	{
	case 1://case������֮���пո���case����Ϊ�������ʽ
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break;
	default://���Ķ��У������ÿ�
		printf
			("���������\n");
		break;

	}
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("������\n");
		break;
	case 6:
	case 7:
		printf("��Ϣ��\n");
		break;
	default://���Ķ��У������ÿ�
		printf
			("���������\n");
		break;
	}
	return 0;
}
