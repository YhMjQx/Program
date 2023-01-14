#define  _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#define MAX 1000
#define MAX_NAME 1000
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
enum
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_SEX];
	char addr[MAX_ADDR];
};
struct contact
{
	struct PeoInfo data[MAX];
	int size;
};
//ÉùÃ÷º¯Êý
void InitContact(struct contact* ps);
void Addcontact(struct contact* ps);
void Showcontact(const struct contact* ps);
void Delcontact(struct contact* ps);
void Searchcontact(const struct contact* ps);
void Modifycontact(struct contact* ps);
void Sortcontact(struct contact* ps);