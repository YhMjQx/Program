#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//void* malloc(size_t size)
	int* p = (int *)malloc(40);//����40���ֽڵĿռ䣬����malloc���ٿռ�ʧ�ܾͻ᷵��һ��NULL��malloc�����ķ�������Ӧ����void*������һ�������������Ҫ����ǿ������ת����
	if (p = NULL)
	{
		printf("%s\n", strerror(errno));
		//�������ִ�й����з����˴��󣬻Ὣ�����븳��errno��Ȼ��ͨ��strerror�������ҵ��������Ӧ�Ĵ�����Ϣ��Ȼ���ҾͿ��Դ�ӡ����
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			*(p + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));
		}
	}
	//ÿ����̬����Ŀռ䲻��ʹ�õ�ʱ�򣬾�Ӧ����free��������ϵͳ�����ǵ�����һ��freeֻ�ܽ����뵽�Ŀռ�黹������ָ����ָ���λ������û�з����ı䣬���ǣ��黹֮��Ӧ����ָ�븳��NULL
	free(p);
	p = NULL;
	return 0;
}