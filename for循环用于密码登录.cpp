#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };
	for (i = 0; i < 3; i++)
	{
		printf("��������ȷ������\n");
		scanf("%s", password);
		if (strcmp(password, "YhMjQx") == 0);//==�������������ַ���������жϣ���������������ַ���֮�䣬�ͱ���˸�ֵ����˼
		{
			printf("������ȷ\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
		
		if (3 == i)
		{
			printf("�����������������˳�����\n");
		}
	}
	return 0;
}
