#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void*calloc(size_t num , size_t size)
	//size_t num - Ԫ�صĸ���
	//size_t size - ÿ��Ԫ�ص��ֽڴ�С
	//free�������ͷŶ�̬���ٵĿռ��
	//calloc������Ϊnum����СΪsize��Ԫ�ؿ���һ��ռ䣬���Ұ�ÿһ�ֽڳ�ʼ��Ϊ0
	//calloc��malloc����������calloc�ٷ��ص�ַ֮ǰ�������Ŀռ��ÿ���ֽڳ�ʼ��Ϊ0
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)//ע�ⲻҪԽ����ʣ����ٶ��ٿռ���ö��ٿռ�
		{
			printf("%d ", *(p + i));
		}
		printf("\n");
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
		printf("\n");
	}
	free(p);//�����ͷŵ�Ӧ���Ƕ�̬�ռ俪�ٵ��ڴ�ռ䣬Ҳ���Ƕ����ڲ����ڴ�ռ�
	p = NULL;
	return 0;
}