#include<stdio.h>
#include<stdio.h> //strcpy(a.name,"����");     �������Ĵ��룬�Ҿ��ܰ�name�ɡ������ʷ����Ϊ�����
struct Book//��struct�����Լ����һ���ṹ�����ͣ�struct�����ṹ��ؼ��֣���ʵ�����ڹ���һ������
{
	char name[20];
	long long price;//8���ֽڣ���˼۸���Ǹ���λ��
};//ע�⣬����ķֺſɲ��ܶ�!!!
int main()//���ýṹ�����ͣ�����һ���ṹ�����
{
	struct Book a = { "�����ʷ\n", 39393939 };
	printf("������%s", a.name);//��һ�ִ�ӡ��ʽ    .��һ�����������ڽṹ��������������ҵ��Լ�����ĳ�Ա
	printf("�۸�%d\n", a.price);
	struct Book* pa = &a;
	printf("������%s\n", (*pa).name);//ע�⣬�����ַ���������һ����Ҫ��С���ţ��ڶ��ִ�ӡ��ʽ
	printf("�۸�%d\n", (*pa).price );
	printf("������%s\n", pa->name);//�����ִ�ӡ��ʽ���ṹ��ָ��->��Ա
	printf("�۸�%d\n", pa->price);
	return 0;
}