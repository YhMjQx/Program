#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	//让cur代替pq->head，为了不动pq->head
	while (cur != NULL)
	{
		//由于free(cur)掉之后，cur就找不到之后的囧恩点了，所以用一个next提前接收cur->next
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)//说明此时队列为空的情况
	{
		//那此时就让pq->head和pq->tail都指向新创建的节点
		pq->head = newnode;
		pq->tail = newnode;
	}
	else//如果队列不为空，那么就将节点连接在队尾上
	{
		pq->tail->next = newnode;
		//但是也别忘了移动tail，让新的tail往后移动
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)//这个删除数据是从头开始删
{
	assert(pq);//判断Queue不是空
	assert(!QueueEmpty(pq));//判断队列是否为空
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)//此时说明队列为空
	{
		//next为空给到pq->head，此时pq->head置空，但是pq->tail还没有置空
		pq->tail = NULL;//为了防止野指针问题，所以判断一下符合条件之后然后就置空
	}
}
QDataType QueueFront(Queue*pq)//取队头的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue*pq)//取队尾的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq)//计算队列个数的大小
{
	assert(pq);
	assert(!QueueEmpty(pq));
	int size = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);
	return pq->head == NULL;
}