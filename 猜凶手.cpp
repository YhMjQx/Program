#include<stdio.h>
int main()
{
	//四个凶手：已知三个人说了真话，1个人说了假话
	//A:不是我
	//B:是C
	//C:是D
	//D:C在胡说
	//写一个程序确定哪个人是凶手
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