#include<stdio.h>
typedef struct S
{
	char* ch1;
	char* ch2;
	char* ch3;
	int a;
}stu;
void Init( stu* ps)
{
	ps->ch1 = "YMQ"; 
	ps->ch2 = "HJX";
	ps->ch3 = "YhMjQx";
	ps->a = 1314;
}
//�������Ϊ"YMQ""HJX""YhMjQx"д�ڴ����ڲ��൱���ǳ��������Ĵ洢�ռ��ɾ�̬���ṩ�������������൱������ջ������ռ�
//�������������������д��char ch1[39];ps->ch1="YMQ";�����Ĵ���������Ǵ����
//�������޸ķ�����
//1.�������ַ������飬���Ƕ���һ���ַ���ָ�룬Ҳ������һ��ָ��ָ��̬�����ַ���
//2.���ڴ����ڲ�д��"YMQ""HJX""YhMjQx"�����Ĵ��룬����дһ��scanf() / gets()�Ӽ����ϻ�ȡ����
void Print(const S* ps)
{
	printf("%s\n", ps->ch1);
	printf("%s\n", ps->ch2);
	printf("%s\n", ps->ch3);
	printf("%d\n", ps->a);
}
int main()
{
	S stu = { 0 };
	//printf("%s\n", s.ch1);
	//printf("%s\n", s.ch2);
	//printf("%s\n", s.ch3);
	//printf("%d\n", s.a);
	Init(&stu);//��ʼ��Ҫ��ı�ṹ���ڲ��ĵ�ֵӦ�ô���ַ
	Print(&stu);
	return 0;
}