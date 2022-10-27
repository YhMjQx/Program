#include<stdio.h>
int main()
{
	int day;
	scanf("%d", &day);
	switch (day)//switch后面没有分号，其后面的（）中的为整形表达式
	{
	case 1://case和数字之间有空格，且case后面为常量表达式
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期天\n");
		break;
	default://放哪都行，放最后好看
		printf
			("您输入错误\n");
		break;

	}
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	default://放哪都行，放最后好看
		printf
			("您输入错误\n");
		break;
	}
	return 0;
}
