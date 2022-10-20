#include<stdio.h>
int a = 39;//全局变量
int main()
{
	int a = 93;//局部变量，此时printf也只能在大括号内使用才有效
	printf("%d\n", a);//当局部变量和全局变量的名字相同时，局部变量优先输出
	printf("头文件上面的文件右键，属性，系统，子系统，控制台,修改后用于输出\n");
	return 0;
}