#include<stdio.h>
enum Sex//ö��-һһ�о٣���ؼ�Ϊenum
{
	MALE,//ע������Ķ���
	FEMALE,//ע������Ķ���
	SECRET
	//��������Ϊö�ٳ������ǲ��ܸĵġ�
};//����ķֺź���Ҫ��Ī����
int main()
{
	//ö�ٳ������ܸģ����������������������ȴ��ͨ����enum Sex sex=SECRET;color=FEMALE;�����иı�.
	printf("%d\n", MALE);//0
	printf("%d\n", FEMALE);//1
	printf("%d\n", SECRET);//2
	return 0;
}