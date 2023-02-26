#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDatapyde;
typedef struct SListNode
{
	SLDatapyde data;
	struct SListNode* next;
}SLNode;
void SLPrint(SLNode* phead);
void SLPushBack(SLNode** pphead, SLDatapyde x);
void SLPushFront(SLNode** pphead, SLDatapyde x);
void SLPopBank(SLNode** pphead);
