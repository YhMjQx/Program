#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(S));
	ps->arr = (int *)malloc(5 * sizeof(int));
	//�����Ŀ����ڴ�ķ�ʽ��n���ڴ�ռ��srr���ڴ�ռ䲻һ���ͷ���һ��
	int i = 0;
	if ((ps != NULL) && (ps->arr != NULL))
	{
		for (i = 0; i < 5; i++)
		{
			ps->arr[i] = i;
		}
	}
	//���裬�����ڿ��ٵĿռ䲻�����ˣ���Ҫ���¿��ٿռ䣬��
	int* pos = (int*)realloc(ps->arr, 10 * sizeof(int));
	if (pos != NULL)
	{
		ps->arr = pos;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//������Ҫ�ͷſռ䣬������Ҫ��ô�ͷţ�ע�⣬����������malloc����ô�Ҿ���Ҫ�ͷ����οռ䣬��Ҫע���Ⱥ�˳��
	//�������ȿ��ٵ���ps�����ſ�����ps->arr,��������Ҫ��ps������ps->arr���Ա��ڷ����ڴ�й©��������Ӧ���Ȱ�
	//arrָ�����Ƭ�ռ��ͷŵ������ͷ�ps��Ҳ����˵���ȿ��ٵĺ��ͷţ��󿪱ٵ����ͷ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
//������Ƚ�֮�£�����������е㣺
//1.mallocʹ�ý��٣���������ʽ���
//2.mallocʹ���ڴ�ռ���������ߣ������˿ռ���Ƭ�Ĳ���
//3.�ڴ�ռ�����������Ч�ʸ���