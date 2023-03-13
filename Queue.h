#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
//这个结构是队列的节点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
//这个结构是指向队列节点的指针
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue*pq);//取队头的数据
QDataType QueueFBack(Queue*pq);//取队尾的数据
int QueueSize(Queue* pq);//计算队列个数的大小
bool QueueEmpty(Queue* pq);//判断队列是否为空