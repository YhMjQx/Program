#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int arr[];//���������Ա֮ǰ�������ٰ���һ����Ա
};
int main()
{
	//�������飺�ṹ���е����һ��Ԫ��������δ֪��С�����飬�������������Ա
	//����ṹ���С��ʱ�����������Ա�����ڼ��㷶Χ֮��
	printf("%d\n", sizeof(S));
	int i = 0;
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	//�����Ŀ����ڴ�ķ�ʽ��n���ڴ�ռ��srr���ڴ�ռ���ܵĿ�����һ��
	if (ps != NULL)
	{
		ps->n = 39;
		for (i = 0; i < 5; i++)
		{
			ps->arr[i] = i;
		}
	}
	//�������ڿ��ٵĿռ䲻�����ˣ�����Ҫ�ٿ���5�����εĿռ�
	struct S* pos = (struct S*)realloc(ps->arr, sizeof(struct S) + 10 * sizeof(int));
	if (pos != NULL)
	{
		ps = pos;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	free(ps);//�������Ѿ����¿��ٵĿռ�ĵ�ַpos������p������������ֻ��Ҫ�ͷ�psָ�����Ƭ�ռ�ͺ���
	ps = NULL;
	return 0;
}
