#include<stdio.h>
#include<stdlib.h>
struct S
{
	int n;
	int arr[];//柔性数组成员之前必须至少包含一个成员
};
int main()
{
	//柔性数组：结构体中的最后一个元素允许是未知大小的数组，叫做柔性数组成员
	//计算结构体大小的时候，柔性数组成员并不在计算范围之内
	printf("%d\n", sizeof(S));
	int i = 0;
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	//这样的开辟内存的方式让n的内存空间和srr的内存空间紧密的开辟在一起
	if (ps != NULL)
	{
		ps->n = 39;
		for (i = 0; i < 5; i++)
		{
			ps->arr[i] = i;
		}
	}
	//假设现在开辟的空间不够用了，我需要再开辟5个整形的空间
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
	free(ps);//由于我已经将新开辟的空间的地址pos赋给了p，于是最终我只需要释放ps指向的那片空间就好了
	ps = NULL;
	return 0;
}
