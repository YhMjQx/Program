#include<stdio.h>
int main()
{
	//size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");
	//wb���Զ����Ƶ���ʽд���ļ�
	fwrite(&a, 4, 1, pf);
	//��һ��������Ҫд������ݵ��׵�ַ
	//�ڶ���������Ҫд������ݵ��ֽڴ�С
	//������������Ҫд������ݵĸ���
	//���ĸ�������Ҫд����ļ����ļ�ָ��
	fclose(pf);
	pf = NULL;
	//�����ļ�������
	//1.Դ�����ļ�����׺Ϊ.c
	//2.Ŀ���ļ���windows������׺Ϊ.obj
	//3.��ִ�г���windows������׺Ϊ.exe 
	//�ַ�һ����ASCLL��ʽ�洢����ֵ�����ݼȿ�����ASCLL��ʽ�洢��Ҳ�����ö�������ʽ�洢
	return 0;
}