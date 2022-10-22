#include<stdio.h>
int main()
{
	int line = 0;//定义变量
	printf("学技术，提能力，合胡杨\n");
	while (line < 20000)//循环语句
	{
		printf("学C语言，提升技术，为了胡杨%d\n",line);//要想把line的值用printf打出来，则别忘了%d，把值给line
		line++;//line自加
	}
	if (line >= 20000)
		printf("有技术，有能力，胡杨合\n");
	return 0;
}
