#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDatapyde;
typedef struct ListNode
{
	struct ListNode* prev;
	LTDatapyde data;
	struct ListNode* next;
}LTNode;
LTNode* ListInit();
void ListPrint(LTNode* phead);
void PushBack(struct ListNode* phead, LTDatapyde x);
void PopBack(struct ListNode* phead);
void PushFront(struct ListNode* phead, LTDatapyde x);
void PopFront(struct ListNode* phead);
LTNode* ListFind(struct ListNode* phead, LTDatapyde x);
void ListInsert(LTNode* pos, LTDatapyde x);
void ListErase(LTNode* pos);
void ListDestroy(LTNode* phead);


