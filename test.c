#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <contact.h>
void menu()
{
	printf("***********************************");
	printf("****** 1.add           2.del ******");
	printf("****** 3.search      4.modify******");
	printf("****** 5.show          6.sort******");
	printf("************  0.exit  *************");
	printf("***********************************");
}
int main()
{
	int input = 0;
	//����ͨѶ¼
	struct contact con;
	Initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SEARCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case SORT:
			Sortcontact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼��");
			break;
		default:
			printf("ѡ�����������ѡ��:>");
			break;
		}
	} while (input);
	return 0;
}