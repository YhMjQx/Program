#include"Stack.h"
StackText()
{
	ST st;
	StackInit(&st);
	for (int i = 0; i < 5; i++){
		StackPush(&st, i);
	}
	//StackPop(&st);
	//StackPop(&st);
	//��ô��������ӡջ�����������
	//�����ʼ�Ҷ����top��0����������ҵ�top��ʾ����ջ�����ݵĸ����������ܳ䵱�±�ʹ�ã���Ϊ��ʱ��top���±��һ
	//������Ӧ��ѡ������top��һ��Ȼ����top=0��ʱ�������ѭ�����ӡ����
	//��Ȼ����Ҳ����ѡ���ʼ��top=-1�������������ͽ���ˣ������ֻ��������������
	st.top -= 1;
	while (!StackEmpty(&st)){
		printf("%d ", st.a[st.top]);
		StackPop(&st);
	}
	printf("%d", st.a[st.top]);
	StackDestroy(&st);
}
//OJ�⣺��Ч������
//����һ��ֻ����'(', ')', '[', ']', '{', '}'���ַ���s���ж��ַ����Ƿ���Ч
//��Ч�ַ��������㣺�����ű�������ͬ���͵������űպϣ������ű�������ȷ��˳��պ�
bool isValid(char* s)//��Ȼ��Ҫ����Ч��ʹ��������������뽫STDatatype����Ϊchar
{
	ST st;
	StackInit(&st);
	while (*s){
		//������������ַ������ַ��������žͽ�ջ
		if (*s == '(' || *s == '[' || *s == '{'){
			StackPush(&st,*s);
			++s;
		}
		//������������ַ���������ַ����������ţ����������ţ���������Ҫ����ջ��������
		//��ջ�����ڴ�ʱ���������������ַ����бȽ�
		else{
			//��ʱҪ�жϣ�����ս�������һ�������ŵĻ���ʱջ��Ϊ��StackEmpty(&st)������ֵ����ʱ����û����������������ƥ�䣬���Է���false
			if (StackEmpty(&st)){
				StackDestroy(&st);
				return false;
			}
			//��top���������ų�ջ
			STDataType top = StackTop(&st);
			//��ջ��֮����stackPop��ջ������ݸ�����һ		
			StackPop(&st);
			//���ڽ��бȽ�,���û��ƥ���ϣ��ͷ���false,��֮ƥ�����˾���s++
			if ((*s == ')'&&top != '(')
				|| (*s == ']'&&top != '{')
				|| (*s == '}'&&top != '{')){
				StackDestroy(&st);
				return false;
			}
			else{
				++s;
			}
		}
		//���ջ�в�Ϊ�գ�˵����ʱstackEmpty(&st)����ֵΪ�٣���ʱջ�л���������δ��������ƥ�䣬��ʱӦ�÷���false
		bool ret = stackEmpty(&st);
		StackDestroy(&st);
		return ret;
	}
}
int main()
{
	StackText();
	//return 0;
}
//������ջʵ�������ȳ��Ķ��еĲ���������Ӧ��֧�ֶ��е����л���������Push��Pop��Peek��empty��
//ʵ��MyQueue�ࣺ
//void push(int x) ��Ԫ��x�Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�շ���true����֮����false
//����˼·��
//1.pushSTջ���������ݣ�popSTջ����������
//2.�����ݵ�ʱ��������Ҫ��pushSTջ�ڵ�����ת�Ƶ�popSTջ�ڣ�Ȼ���popSTջ������

typedef struct{
	ST pushST;
	ST popST;
}MyQueue;

MyQueue* myQueueCreate(){
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);
}

void myQueuePush(MyQueue* obj,int x){
	StackPush(&obj->pushST, x);
}
//���popSTջ�������ݣ���ô��ֱ�ӳ�����
//���popSTջ��û�����ݣ���ô���Ȱ�pushSTջ�ڵ������ƶ���popSTջ�ڣ�Ȼ���ٴ�popSTջ������
int myQueuePop(MyQueue* obj){
	if (StackEmpty(&obj->popST)){
		while (StackEmpty(&obj->pushST)){
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	//���popST��Ϊ�գ���ô��ֱ�Ӵ����г����ݾͺ���
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}
//���ض��п�ͷ�����ݣ����Ƕ����п���Ϊ��
int mystackPeek(MyQueue* obj){
	assert(obj);
	if (StackEmpty(&obj->popST)){
		while (StackEmpty(&obj->pushST)){
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}
bool myQueueEmpty(MyQueue* obj){
	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}
void myQueueFree(MyQueue* obj){
	assert(obj);
	StackDestroy(&obj->popST);
	StackDestroy(&obj->pushST);
	StackDestroy(&obj);
}