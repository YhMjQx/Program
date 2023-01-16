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
	//这样的开辟内存的方式让n的内存空间和srr的内存空间不一定就放在一起
	int i = 0;
	if ((ps != NULL) && (ps->arr != NULL))
	{
		for (i = 0; i < 5; i++)
		{
			ps->arr[i] = i;
		}
	}
	//假设，我现在开辟的空间不够用了，需要重新开辟空间，则
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
	//这里需要释放空间，但具体要怎么释放，注意，我用了两次malloc，那么我就需要释放两次空间，但要注意先后顺序
	//由于我先开辟的是ps，随后才开辟了ps->arr,所以我需要用ps来保留ps->arr，以便于放置内存泄漏，所以我应该先把
	//arr指向的那片空间释放掉，在释放ps，也就是说，先开辟的后释放，后开辟的先释放
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
//所以相比较之下，柔性数组的有点：
//1.malloc使用较少，代码出错率降低
//2.malloc使得内存空间利用率提高，减少了空间碎片的产生
//3.内存空间连续，访问效率更高