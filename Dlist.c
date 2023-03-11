#include"DList.h";
LTNode* ListInit()
{
	//开辟一个头节点，做哨兵位，这是一个带哨兵位的双向循环链表
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
//带有头节点，就不需要传二级指针
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
	assert(phead->next != phead);//这种情况是为了防止删到最后把链表删成空了，删到只剩头节点就停止
	//我可以用LTNode* tailPrev来代替tail->prev
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
	////把newnode的prev和哨兵位连接起来
	//phead->next = newnode;
	//newnode->prev = phead;
	////把newnode的next和后面的next连接起来
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
	//用新的poePrev来代替pos->prev，更加方便，可读性高，且不会有顺序的烦恼
	LTNode* posPrev = pos->prev; 
	//开始插入
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
//删除pos的位置
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