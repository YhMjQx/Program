#include<stdio.h>
#pragma pack(1)//�޸�Ĭ�϶�����Ϊ1
struct H
{
	char a;
	int b;
};
#pragma pack()//ȡ�����õĶ�����
struct Y
{
	char a;
	int b;
};
int main()
{
	//�����ļ���ṹ��Ĵ�С��ʱ�򣬶���ṹ�������Ҫ�ɲ�Ҫ,Ҫ��ʱ��;ͼ�������Ĵ�С���ɣ���Ҫ��ʱ��ֱ�Ӽ���ṹ��Ĵ�С����
	//struct H s1 = { 0 };
	printf("%d\n", sizeof(H));//�����˽ṹ�����֮���д��Ϊprintf("%d\n", sizeof(s1));
	//struct Y s2 = { 0 };
	printf("%d\n", sizeof(Y));//�����˽ṹ�����֮���д��Ϊprintf("%d\n", sizeof(s2));
	return 0;
}