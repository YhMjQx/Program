#define  _CRT_SECURE_NO_WARNINGS 1
#include <contact.h>
//ʵ�ֺ���
static int FindByName(const struct contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(name, ps->data[i].name))
		{
			return i;
		}
	}
	return -1;
}
void InitContact(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void Addcontact(struct contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷���ӣ�");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ:>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ���");
	}
}
void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
	}
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t", "����", "����", "�Ա�", "�绰", "סַ");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t",
			ps->data[ps->size].name,
			ps->data[ps->size].age,
			ps->data[ps->size].sex,
			ps->data[ps->size].tele,
			ps->data[ps->size].addr);
	}
}
void Delcontact(struct contact* ps)
{
	//����Ҫɾ��������ʲôλ��
	char name[MAX_NAME];
	printf("��������Ҫɾ������ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	//������������֮��û�ҵ�����ϵ�ˣ���˵������ϵ�˲�����
	if (pos == -1)
	{
		printf("��Ҫ���ҵ���ϵ�˲����ڣ�");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ����ϵ�˳ɹ���");
	}
}
void Searchcontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ���ҵ���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("��Ҫ���ҵ���ϵ�˲����ڣ�");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\t",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}
void Modifycontact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸���ϵ�˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ���");
	}
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp((struct contact*)e1,(struct contact*)e2);
}
void Sortcontact(struct contact* ps)
{
	int sz = sizeof(ps->data) / sizeof(ps->data[0]);
	qsort(ps->data, sz, sizeof(ps->data[0]), cmp_by_name);
	printf("����������ɹ���");
}
