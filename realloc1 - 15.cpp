#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void* realloc(void* memblock,size_t size)
	//void* memblock - ֮ǰ���ٵ��ڴ濪����Ҫ�ı���ڴ��ĵ�ַ��
	//size_t size - �¿���֮����ֽڴ�С
	int* p = (int *)malloc(20);
	if (p == NULL)//�������Ҫ��һ��Ҫ�ж�һ�¿����Ƿ�ɹ�
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)//ע�ⲻҪԽ����ʣ����ٶ��ٿռ���ö��ٿռ�
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	//ʹ��malloc������һ��20���ֽڴ�С�Ŀռ䣬��������20���ֽڵĿռ䲻���ã�ϣ���ܿ���40���ֽڴ�С�Ŀռ�
	//����Ϳ�����realloc��������̬�ڴ����
	//realloc������ʹ��ע�����
	//1.���pָ��Ŀռ�����㹻���ڴ�ռ����׷�ӣ���ֱ��׷�ӣ����֮�󷵻�p
	//2.���pָ��Ŀռ��û���㹻���ڴ�ռ����׷�ӣ���realloc�����¿���һ���µ��������Ҫ����ڴ�����
	//  ���Ұ�ԭ���ڴ�ռ��ڵ����ݿ����ŵ�����µ��ڴ�ռ䣬Ȼ��ѾɵĿռ��ַ�ͷŵ�����󷵻�����µ��ڴ�ռ����ʼ��ַ
	//3.����һ���µ�ָ�����������realloc�����ķ���ֵ
	int* pos = (int *)realloc(p, 40);
	if (pos != NULL)
	{
		p = pos;
		int i = 0;
		for (i = 5; i < 10; i++)//ע�ⲻҪԽ����ʣ����ٶ��ٿռ���ö��ٿռ�
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);//�����ͷŵ�Ӧ���Ƕ�̬�ռ俪�ٵ��ڴ�ռ䣬Ҳ���Ƕ����ڲ����ڴ�ռ�
	p = NULL;
	return 0;
}