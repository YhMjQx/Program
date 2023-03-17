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
//仅用两个队列实现一个先入后出的栈的4种基本操作（push,top,pop,emrty）
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




//循环队列的实现。
//循环队列是一种线性数据结构，其操作表现基于FIFO(先进先出)原则并且
//队尾被连接在对首之后，形成一个循环，他也被称为“环形缓冲器”。
//循环队列的一个好处就是我们可以利用这个队列之前用过的空间。在一个普通队列里面
//一但一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
//但是使用循环队列，我们就能使用这些空间去存储新的值。
//循环队列即可使用数组实现，也可使用链表实现
//但是循环链表的重点在于多创建一个空间！！！
//
//循环队列，无论使用数组实现还是链表实现，都要多开一个空间，也就意味着
//要实现一个存k个数据的循环队列，要开k+1个空间，否则无法实现判空和判满

//你的实现应该支持如下操作：
//MyCircularQueue(k); 构造器，设置队列长度为k
//Front; 从队首获取元素。如果队列为空，返回 - 1
//Rear; 获取队尾元素。如果队列为空，返回 - 1
//enQueue(value); 向循环队列里面插入一个元素。如果成功插入则返回真
//isEmpty(); 检查循环队列是否为空
//isFull();检查循环队列是否已满
typedef struct{
	int* a;
	int tail;
	int front;
	int k;//存储数据的个数
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj){
	//当tail=front的时候环形链表为空
	return obj->tail == obj->front;
}
bool myCircularQueueIsFull(MyCircularQueue* obj){
	//这种条件下，
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}
MyCircularQueue* myCircularQueueCreat(int k){

	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int)*k);
	cq->tail = cq->front = 0;
	cq->k = k;
	return cq;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value){
	//既然要插入数据，那么肯定需要先判断环形链表是否为空还是满
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	else{
		//将数据插入环形链表之后，要让tail++，但是如果当tail到数组的最后一个的话
		//那么就需要让tail返回到数组的头部，那么就需要让tail%（k+1）
		//当然，就算tail没有走到最后，tail取模之后对tail的值也没有任何影响
		obj->a[obj->tail] = value;
		obj->tail++;
		obj->tail %= (obj->k + 1);
		return true;
	}
}
bool myCircularQueueDeQueue(MyCircularQueue* obj){//删除环形链表中的数据
	//要想删除，那么链表一定不能为空
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	else{
		obj->front++;
		//和上面插入数据的时候一样，如果front在删除数据的过程中，走到了数组的最后一个
		//那么就需要让front回到数组的头部，那么就需要front % (k+1)
		//当然，就算front没走到最后，我取模之后对front的值不会造成任何影响
		obj->front %= (obj->k + 1);
		return true;
	}
}
int myCircularQueueFront(MyCircularQueue* obj){
	//要想取对头的元素，那么队列一定不能为空
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	else{
		return obj->a[obj->front];
	}
}
int myCircularQueueRear(MyCircularQueue* obj){
	//要想取队尾的元素，那么队列也一定不能为空
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	else{
		//在这里有一个问题，如果tail在数组头部，但是尾部的数据却在数组的最后。
		//此时想要找到数组尾部并不方便，所以又用到了模的运算
		int i = (obj->tail + obj->k) % (obj->k + 1);
		return obj->a[i];
	}
}
void myCircularQueueFree(MyCircularQueue* obj){
	//注意，这里依旧是结构嵌套结构，
	free(obj->a);
	free(obj);
}