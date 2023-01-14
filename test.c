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
	//创建通讯录
	struct contact con;
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择:>");
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
			printf("退出通讯录！");
			break;
		default:
			printf("选择错误，请重新选择:>");
			break;
		}
	} while (input);
	return 0;
}