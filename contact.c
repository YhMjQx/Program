#define  _CRT_SECURE_NO_WARNINGS 1
#include <contact.h>
//实现函数
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
		printf("通讯录已满，无法添加！");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("添加成功！");
	}
}
void Showcontact(const struct contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空！");
	}
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t", "名字", "年龄", "性别", "电话", "住址");
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
	//查找要删除的人在什么位置
	char name[MAX_NAME];
	printf("请输入您要删除的联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	//如果数组遍历完之后还没找到该联系人，就说明该联系人不存在
	if (pos == -1)
	{
		printf("您要查找的联系人不存在！");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除联系人成功！");
	}
}
void Searchcontact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入您要查找的联系人的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("您要查找的联系人不存在！");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\t", "名字", "年龄", "性别", "电话", "住址");
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
	printf("请输入要修改联系人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("要修改的联系人不存在！");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功！");
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
	printf("按姓名排序成功！");
}
