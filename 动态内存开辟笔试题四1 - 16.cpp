#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void test(void)
{
	char* str = (char*)malloc(20);//һ���������Ĵ��������������֮����Ҫ��if�жϷ��ص�ָ���Ƿ�ΪNULL
	if (str == NULL)
	{
		//Ӧ�ý�������
	}
	strcpy(str, "YhMjQx");
	printf(str);
	free(str);//ע�⣬����������ǰ��free�ͷ���str֮����Ϊfree�ͷſռ�֮�󲢲����str�ÿգ�����str�ͱ����Ұָ�룬
	//��Ұָ����в�������һ���ǳ�Σ�յ��£����ǣ�����free֮��һ��Ҫ�ֶ��ÿ�
	str = NULL;//���û����һ������������ͻ��кܴ�Σ��
	if (str != NULL)
	{
		strcpy(str,"HY1314");
		printf("%s\n", str);
	}
}
int main()
{
	test();
	return 0;
}