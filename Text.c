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