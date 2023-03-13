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
	//��cur����pq->head��Ϊ�˲���pq->head
	while (cur != NULL)
	{
		//����free(cur)��֮��cur���Ҳ���֮��ć�����ˣ�������һ��next��ǰ����cur->next
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
	if (pq->head == NULL)//˵����ʱ����Ϊ�յ����
	{
		//�Ǵ�ʱ����pq->head��pq->tail��ָ���´����Ľڵ�
		pq->head = newnode;
		pq->tail = newnode;
	}
	else//������в�Ϊ�գ���ô�ͽ��ڵ������ڶ�β��
	{
		pq->tail->next = newnode;
		//����Ҳ�������ƶ�tail�����µ�tail�����ƶ�
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq)//���ɾ�������Ǵ�ͷ��ʼɾ
{
	assert(pq);//�ж�Queue���ǿ�
	assert(!QueueEmpty(pq));//�ж϶����Ƿ�Ϊ��
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL)//��ʱ˵������Ϊ��
	{
		//nextΪ�ո���pq->head����ʱpq->head�ÿգ�����pq->tail��û���ÿ�
		pq->tail = NULL;//Ϊ�˷�ֹҰָ�����⣬�����ж�һ�·�������֮��Ȼ����ÿ�
	}
}
QDataType QueueFront(Queue*pq)//ȡ��ͷ������
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue*pq)//ȡ��β������
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq)//������и����Ĵ�С
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
bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��
{
	assert(pq);
	return pq->head == NULL;
}