#include<stdio.h>
char* Getmemory()
{
	char p[] = "YhMjQx";
	return p;
}
//����ջ�ռ�ĵ�ַ������
//�������߳������ʱ��pָ�����һƬ�ռ��Ѿ������ˣ��Ѿ����ظ��˲���ϵͳ�����ڵ�p��һ��û��ָ���κοռ��ָ�����
//���ǣ����ڽ�p����str�ٴ�ӡ�Ļ���str�����Ҳ�����Ӧ�Ŀռ䣬���Դ�ӡ�����ľ�������
void test()
{
	char* str = NULL;//һ�������Ҫ��str��ʼ��ΪNULL����ֹҰָ�����⣬��ΪҰָ��Ľ������п�����ɷǷ�����
	str = Getmemory();
	printf(str);
}
int main()
{
	test();
	return 0;
}