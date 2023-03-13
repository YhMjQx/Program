#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
//����ṹ�Ƕ��еĽڵ�
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
//����ṹ��ָ����нڵ��ָ��
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue*pq);//ȡ��ͷ������
QDataType QueueFBack(Queue*pq);//ȡ��β������
int QueueSize(Queue* pq);//������и����Ĵ�С
bool QueueEmpty(Queue* pq);//�ж϶����Ƿ�Ϊ��