#include"SList.h"
SLNode* BuyListNode(SLDatapyde x)
{
	SLNode* SLnewnode = (SLNode*)malloc(sizeof(SLNode));
	if (SLnewnode == NULL)
	{
		assert(SLnewnode != NULL);
		exit(-1);
	}
	SLnewnode->data = x;
	SLnewnode->next = NULL;
}
void SLPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
void SLPushBack(SLNode** pphead, SLDatapyde x)
{
	SLNode* SLnewnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = SLnewnode;
	}
	//把这一部分放在前面的原因是，防止传进来的是一个空指针，从而导致我没有节点可以去指向
	//于是把这一部分放在前面，先创建一个节点，让我的*pphead不是空，也好让接下来的tail寻找尾部的指针链接
	//因为一旦tail是空的话，就根本无法寻找下一个节点

	else
	{
		//找到尾节点
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = SLnewnode;
	}

}
void SLPushFront(SLNode** pphead, SLDatapyde x)
{
	SLNode* SLnewnode = BuyListNode(x);
	SLnewnode->next = *pphead;
	*pphead = SLnewnode;
}
void SLPopBank(SLNode** pphead)
{
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL)//这是防止一个节点的情况
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//两个及以上的节点个数
	{
		SLNode* tail = *pphead;
		SLNode* prev = NULL;
		//while (tail->next)
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
		/*
		SLNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/
	}
}
void SLPopFront(SLNode** pphead)
{

}
