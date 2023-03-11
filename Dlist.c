#include"DList.h";
LTNode* ListInit()
{
	//����һ��ͷ�ڵ㣬���ڱ�λ������һ�����ڱ�λ��˫��ѭ������
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPrint(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
LTNode* BuyListNode(LTDatapyde x)
{
	//assert(phead);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//����ͷ�ڵ㣬�Ͳ���Ҫ������ָ��
void PushBack(struct ListNode* phead, LTDatapyde x)
{
	assert(phead);
	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyListNode(x);
       
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}
void PopBack(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//���������Ϊ�˷�ֹɾ����������ɾ�ɿ��ˣ�ɾ��ֻʣͷ�ڵ��ֹͣ
	//�ҿ�����LTNode* tailPrev������tail->prev
	//LTNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
	ListErase(phead->prev);
}
void PushFront(struct ListNode* phead, LTDatapyde x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;
	////��newnode��prev���ڱ�λ��������
	//phead->next = newnode;
	//newnode->prev = phead;
	////��newnode��next�ͺ����next��������
	//newnode->next = next;
	//next->prev = newnode;
	ListInsert(phead->next, x);
}
void PopFront(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//LTNode* next = phead->next;
	//LTNode* nextNext = next->next;
	//phead->next = nextNext;
	//nextNext->prev = phead;
	//free(next);
	ListErase(phead->next);
}
LTNode* ListFind(struct ListNode* phead, LTDatapyde x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(LTNode* pos, LTDatapyde x)
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	//���µ�poePrev������pos->prev�����ӷ��㣬�ɶ��Ըߣ��Ҳ�����˳��ķ���
	LTNode* posPrev = pos->prev; 
	//��ʼ����
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
//ɾ��pos��λ��
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}