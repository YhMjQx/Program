#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once
typedef int SLDatatype;
typedef struct
{
	SLDatatype* a;
	int size;//��ʾ����洢�˶��ٸ�����
	int capacity;//����ʵ���ܴ�Ŀռ������Ĵ�С
}SL;

//�ӿں��� -- ��������Ǹ���STL�ߵ�
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL* ps);
void SeqListPushBank(SL* ps, SLDatatype x);
void SeqListPopBank(SL* ps);
void SeqListPushFront(SL* ps, SLDatatype x);
void SeqListPopFront(SL* ps);


