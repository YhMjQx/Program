#include<stdio.h>
#include<stddef.h>
struct Y
{
	char a;
	int b;
	double c;
};
//size_t offsetof(structName ,memberName)����һ���꣬���Դ�����
int main()
{
	//offsetof();����ṹ���Ա��������ڽṹ����ʼλ�õ�ƫ�����Ƕ���
	printf("%d\n", offsetof(struct Y, a));
	printf("%d\n", offsetof(struct Y, b));
	printf("%d\n", offsetof(struct Y, c));
	return 0;
}