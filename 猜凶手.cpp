#include<stdio.h>
int main()
{
	//�ĸ����֣���֪������˵���滰��1����˵�˼ٻ�
	//A:������
	//B:��C
	//C:��D
	//D:C�ں�˵
	//дһ������ȷ���ĸ���������
	int killer = 0;
	for (killer = 'A'; killer < 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("killer is %c\n", killer);
		}
	}
	return 0;
}