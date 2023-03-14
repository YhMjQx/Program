#include"Queue.h"
TextQueue1()
{
	Queue q;
	QueueInit(&q);
	for (int i = 0; i < 5; i++)
	{
		QueuePush(&q, i);
	}
	QueuePop(&q);
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueSize(&q));
	QueueDestroy(&q);
}
int main()
{
	TextQueue1();
	return 0;
}
//������������ʵ��һ����������ջ��4�ֻ���������push,top,pop,emrty��
//ʵ��MySatack�ࣺ
	//void push(int x) ��Ԫ��xѹ��ջ��
	//int pop()�Ƴ�������ջ��Ԫ��
	//int top()����ջ��Ԫ��
	//boolean empty()���ջ�ǿյģ�����true�����򷵻�false
//����˼·��
//1.�����ݣ�����Ϊ�յĶ����룬������һ������Ϊ��
//2.�����ݣ����γ���ͷ�����ݣ�ת�Ƶ���һ�����б��棬ֻʣ���һ�����ݵ�ʱ����pop
typedef struct
{
	Queue q1;
	Queue q2;
}MyStack;
MyStack* myStackCreat()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}
void myStackPop(MyStack* obj)
{
	//��������һ������Ϊ�գ���һ����Ϊ��
	Queue* emptyQ = &obj->q1; 
	Queue* nonemptyQ = &obj->q2;
	//Ȼ������жϣ���������ʵ�������������ô�ĳ���ȷ�����
	if (!QueueEmpty(&obj->q1))//��ʱ˵��q1��Ϊ��
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	//�ò�Ϊ�յĶ����е�Ԫ��ת�Ƶ��ն��е���ȥ����ʣ�����һ��û��ת�Ƶ�ʱ�򣬽����Ԫ�ط��ز�ɾ��
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	//����������ɺ��ó����һ����ɾ��������
	int top = QueueFront(nonemptyQ);
	QueuePop(nonemptyQ);
	return top;
}
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}
bool myStackEmpty(MyStack* obj)
{
	//������������������ʵ��ջ������ֻҪ�������в�ͬʱΪ�գ��ҾͲ��ǿ�
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}
void myStackFree(MyStack* obj)
{
	//ֻ�ܵ��ú����ӿڣ�����ֱ�Ӳ����ṹ
	//����ע�⣬������MyStackǶ�׵�Queue����Queue������ʵָ����еģ�����Ӧ�����ͷŶ��У����ͷ�MyStack
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}