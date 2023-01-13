#include<stdio.h>
int check_sys()
{
	union//由于这个共用体只用一次，与食物选择匿名
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
		printf("小端\n");
	}
	else{
		printf("大端\n");
	}
	return 0;
}