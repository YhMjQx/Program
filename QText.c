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




//ѭ�����е�ʵ�֡�
//ѭ��������һ���������ݽṹ����������ֻ���FIFO(�Ƚ��ȳ�)ԭ����
//��β�������ڶ���֮���γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//ѭ�����е�һ���ô��������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ��������
//һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣
//����ʹ��ѭ�����У����Ǿ���ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//ѭ�����м���ʹ������ʵ�֣�Ҳ��ʹ������ʵ��
//����ѭ��������ص����ڶഴ��һ���ռ䣡����
//
//ѭ�����У�����ʹ������ʵ�ֻ�������ʵ�֣���Ҫ�࿪һ���ռ䣬Ҳ����ζ��
//Ҫʵ��һ����k�����ݵ�ѭ�����У�Ҫ��k+1���ռ䣬�����޷�ʵ���пպ�����

//���ʵ��Ӧ��֧�����²�����
//MyCircularQueue(k); �����������ö��г���Ϊk
//Front; �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1
//Rear; ��ȡ��βԪ�ء��������Ϊ�գ����� - 1
//enQueue(value); ��ѭ�������������һ��Ԫ�ء�����ɹ������򷵻���
//isEmpty(); ���ѭ�������Ƿ�Ϊ��
//isFull();���ѭ�������Ƿ�����
typedef struct{
	int* a;
	int tail;
	int front;
	int k;//�洢���ݵĸ���
}MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj){
	//��tail=front��ʱ��������Ϊ��
	return obj->tail == obj->front;
}
bool myCircularQueueIsFull(MyCircularQueue* obj){
	//���������£�
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
	//��ȻҪ�������ݣ���ô�϶���Ҫ���жϻ��������Ƿ�Ϊ�ջ�����
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	else{
		//�����ݲ��뻷������֮��Ҫ��tail++�����������tail����������һ���Ļ�
		//��ô����Ҫ��tail���ص������ͷ������ô����Ҫ��tail%��k+1��
		//��Ȼ������tailû���ߵ����tailȡģ֮���tail��ֵҲû���κ�Ӱ��
		obj->a[obj->tail] = value;
		obj->tail++;
		obj->tail %= (obj->k + 1);
		return true;
	}
}
bool myCircularQueueDeQueue(MyCircularQueue* obj){//ɾ�����������е�����
	//Ҫ��ɾ������ô����һ������Ϊ��
	if (myCircularQueueIsEmpty(obj)){
		return false;
	}
	else{
		obj->front++;
		//������������ݵ�ʱ��һ�������front��ɾ�����ݵĹ����У��ߵ�����������һ��
		//��ô����Ҫ��front�ص������ͷ������ô����Ҫfront % (k+1)
		//��Ȼ������frontû�ߵ������ȡģ֮���front��ֵ��������κ�Ӱ��
		obj->front %= (obj->k + 1);
		return true;
	}
}
int myCircularQueueFront(MyCircularQueue* obj){
	//Ҫ��ȡ��ͷ��Ԫ�أ���ô����һ������Ϊ��
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	else{
		return obj->a[obj->front];
	}
}
int myCircularQueueRear(MyCircularQueue* obj){
	//Ҫ��ȡ��β��Ԫ�أ���ô����Ҳһ������Ϊ��
	if (myCircularQueueIsEmpty(obj)){
		return -1;
	}
	else{
		//��������һ�����⣬���tail������ͷ��������β��������ȴ����������
		//��ʱ��Ҫ�ҵ�����β���������㣬�������õ���ģ������
		int i = (obj->tail + obj->k) % (obj->k + 1);
		return obj->a[i];
	}
}
void myCircularQueueFree(MyCircularQueue* obj){
	//ע�⣬���������ǽṹǶ�׽ṹ��
	free(obj->a);
	free(obj);
}