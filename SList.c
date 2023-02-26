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
	//����һ���ַ���ǰ���ԭ���ǣ���ֹ����������һ����ָ�룬�Ӷ�������û�нڵ����ȥָ��
	//���ǰ���һ���ַ���ǰ�棬�ȴ���һ���ڵ㣬���ҵ�*pphead���ǿգ�Ҳ���ý�������tailѰ��β����ָ������
	//��Ϊһ��tail�ǿյĻ����͸����޷�Ѱ����һ���ڵ�

	else
	{
		//�ҵ�β�ڵ�
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
	if ((*pphead)->next == NULL)//���Ƿ�ֹһ���ڵ�����
	{
		free(*pphead);
		*pphead = NULL;
	}
	else//���������ϵĽڵ����
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
