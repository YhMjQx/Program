#include<stdio.h>
int check_sys()
{
	union//�������������ֻ��һ�Σ���ʳ��ѡ������
	{
		char h;
		int y;
	}hy;
	hy.y = 1;
	return hy.h;
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("С��\n");
	}
	else{
		printf("���\n");
	}
	return 0;
}