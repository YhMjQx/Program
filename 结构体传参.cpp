#include<stdio.h>
typedef struct stu//typedef����������þ���������
{
	char name[20];
	char id[8];
	char sex[5];
	char age[4];
}stu;
void print1(stu s)
{
	printf("����: %s\n", s.name);
	printf("��������:%s\n", s.id);
	printf("�Ա�: %s\n", s.sex);
	printf("����:%s\n", s.age);
}
void print2(stu* ps)
{
	printf("����: %s\n", ps->name);
	printf("��������:%s\n", ps->id );
	printf("�Ա�: %s\n", ps->sex );
	printf("����:%s\n", ps->age );
}
int main()
{
	printf("����������������˵ǳ�������\n");
	printf("���Ƚ���Ů����Ϣ��\n");
	stu H = { "������", "040711", "Ů", "18" };
	print1(H);
	printf("�����������з���Ϣ��\n");
	stu Y = { "����ǿ", "041113", "��", "18" };
	print2(&Y);
	return 0;
}