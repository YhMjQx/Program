//线性表：具有相同特性元素的有限序列
//线性表之顺序表 - 本质是数组
//概念及结构在数组的基础上，要求数据是从头并且连续存储的，不能跳跃间隔，完成增删查改
#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, newcapacity*sizeof(SLDatatype));
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPushBank(SL* ps, SLDatatype x)
{
	//当空间不足或者没有空间的时候,我们就扩容
	SeqListCheckCapacity(ps);
	//当空间足够的时候，直接插入数据就好
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBank(SL* ps)
{
	//尾删时需要注意，不要删的越界了
	//温柔尾删方式
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;
	//	ps->size--;
	//}
	//暴力的尾删方式
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDatatype x)
{
	//先看容量够不够，不够的话就增容
	SeqListCheckCapacity(ps);

	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	int begin = 1;
	assert(ps->size > 0);
	//挪动数据
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	//数据挪动一次，begin加加一次，直到begin=size的时候就可以不用在挪动数据了
	//因为先挪动数据后begin++，于是挪动实际上已经完成的时候，此时begin比size小一
	//在进行一次begin++，就会让begin=size，此时数据已经挪动完成，不需要再动了
	//所以此时循环就已经可以停止了,这就是为什么begin < ps->size，而不用加=号
	ps->size--;
}
