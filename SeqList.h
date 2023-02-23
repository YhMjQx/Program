#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#pragma once
typedef int SLDatatype;
typedef struct
{
	SLDatatype* a;
	int size;//表示数组存储了多少个数据
	int capacity;//数组实际能存的空间容量的大小
}SL;

//接口函数 -- 命名风格是根据STL走的
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListDestory(SL* ps);
void SeqListPushBank(SL* ps, SLDatatype x);
void SeqListPopBank(SL* ps);
void SeqListPushFront(SL* ps, SLDatatype x);
void SeqListPopFront(SL* ps);


