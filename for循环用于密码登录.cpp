#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("请输入正确的密码\n");
		scanf("%s", password);
		if (strcmp(password, "YhMjQx") == 0);//==不能用于两个字符串的相等判断，如果用在了两个字符串之间，就变成了赋值的意思
		{
			printf("密码正确\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
		
		if (3 == i)
		{
			printf("三次密码均输入错误，退出程序\n");
		}
	}
	return 0;
}
