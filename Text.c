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
//仅用两个队列实验一个先入后出的栈的4种基本操作（push,top,pop,emrty）
//实现MySatack类：
	//void push(int x) 将元素x压入栈顶
	//int pop()移除并返回栈顶元素
	//int top()返回栈顶元素
	//boolean empty()如果栈是空的，返回true；否则返回false
//核心思路：
//1.入数据，往不为空的对列入，保持另一个队列为空
//2.出数据，依次出对头的数据，转移到另一个队列保存，只剩最后一个数据的时候，再pop
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
	//假设其中一个队列为空，另一个不为空
	Queue* emptyQ = &obj->q1; 
	Queue* nonemptyQ = &obj->q2;
	//然后进行判断，如果假设和实际情况不符，那么改成正确的情况
	if (!QueueEmpty(&obj->q1))//此时说明q1不为空
	{
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}
	//让不为空的队列中的元素转移到空队列当中去，当剩下最后一个没有转移的时候，将这个元素返回并删除
	while (QueueSize(nonemptyQ) > 1)
	{
		QueuePush(emptyQ, QueueFront(nonemptyQ));
		QueuePop(nonemptyQ);
	}
	//上述操作完成后，拿出最后一个，删除并返回
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
	//由于我是用两个队列实现栈，所以只要两个队列不同时为空，我就不是空
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}
void myStackFree(MyStack* obj)
{
	//只能调用函数接口，不能直接操作结构
	//而且注意，我是用MyStack嵌套的Queue，而Queue才是真实指向队列的，所以应该先释放队列，再释放MyStack
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}