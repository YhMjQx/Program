#include<stdio.h>
#include<string.h>
int main()
{
	char arr[] = "YMQ2YXH2YF2ymq2hjx";
	char* p = "2";
	char tmp[] = "YMQ2YXH2YF2ymq2hjx";
	//��forѭ����ʱ�����һ�ε�ȷ������NULL���������ж����������������Ǳ�û�д�ӡ
	for (char* ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
	{
		printf("%s\n", ret);
	}
	//char* strtok(char* str,const char* sep)
	//1.��һ������ָ��һ���ַ�������������0�����߶��sep�ķָ���
	//2.strtok�����ҵ�str����һ���ָ�����λ�ã��������Ϊ\0��Ϊ��β��ͬʱ����ָ��÷ָ���֮ǰ����һ���ַ�����ָ��
	//3.strtok�����ĵ�һ��������ΪNULL�������ҵ�str�еĵ�һ���ָ�����ǣ���Ϊ\0�������λ�ã�
	//4.strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����д�֮ǰ���һ�����ı�ǵ�λ�ÿ�ʼѰ�ҷָ������ҵ���Ĳ���ͬ��
	//5.����ַ����в����и���ķָ�����ǣ��򷵻�NULL����Ҳ����Ϊʲô��whileѭ�������ӡһ��NULL��ԭ��

	//�ҵ���һ���ָ�����������Ҳ����2�������˷ָ�����Ϊ\0��������ָ��������ĵ�ַ
	//����������ӣ�
	//YMQ2YXH2YF2ymq2hjx���ҵ���һ��2����Ϊ\0��Ȼ�󷵻�ָ���һ��Y��ָ���ַ

	//char* ret=strtok(tmp, p);
	//printf("%s\n", ret);
	//while (ret != NULL)
	//{
	//	ret = strtok(NULL, p);
	//	printf("%s\n", ret);
	//}
	return 0;
}