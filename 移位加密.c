#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
struct S
{
	int key;
	char arr[];//���������Ա֮ǰ�������ٰ���һ����Ա
};
//�������飺�ṹ���е����һ����Ա������δ֪��С�����飬�������������Ա
//����ṹ���С��ʱ�����������Ա�����ڼ��㷶Χ֮��

void encode(struct S* ps){

	printf("��Կ��С��");
	scanf("%d", &(ps->key));
	printf("�����ַ�����");
	scanf("%s", ps->arr);

	int i = 0;
	
	for (int i = 0; ps->arr[i] != '\0'; ++i){
		ps->arr[i] = (ps->arr[i] - 'a' + ps->key) % 26 + 'a';
		//�ӡ�a'��Ϊ�˽�ASCIIֵת��Ϊ�ַ��洢
	}
	printf("���ģ�%s\n", ps->arr);

}

void decode(struct S* ps){

	printf("��Կ��С��");
	scanf("%d", &(ps->key));
	printf("�����ַ�����");
	scanf("%s", ps->arr);
	
	int i = 0;
	for (i = 0; ps->arr[i] != '\0'; ++i){
		ps->arr[i] = (ps->arr[i] - 'a' - ps->key) % 26 + 'a';
		
	}
	printf("���ģ�%s\n", ps->arr);
}

int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 100 * sizeof(char));
	//�����Ŀ����ڴ�ķ�ʽ��n���ڴ�ռ��arr���ڴ�ռ���ܵĿ�����һ��

	if (ps == NULL){
		return 0;
	}
	ps->key = 0;

	printf("���ܹ��̣�\n");
	encode(ps);
	printf("���ܹ��̣�\n");
	decode(ps);

	free(ps);
	ps = NULL;
	return 0;
}

