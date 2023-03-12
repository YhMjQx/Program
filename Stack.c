#include"Stack.h"
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->top = 0;
	//ps->top = 0 -- ����������ȸ�ֵȻ��top��++����ʱtopָ�����ջ���������һ��λ��
	//ps->top = -1 -- ����������ȸ�top++,Ȼ���ٸ�ֵ����ʱtopָ�����Ŀǰջ����λ��
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType)*newcapacity);
		if (tmp == NULL)
		{
			printf("%s\n", strerror(errno));
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	//assert(ps->top > 0);
	ps->top--;
	//�����top--���൱��˳������size--������ջ������ݸ���
}
STDataType StackTop(ST* ps)//ȡջ��������
{
	assert(ps);
	assert(!StackEmpty(ps));
	//�൱��assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)//����ջ�ڲ��ж��ٸ�����
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	//if (ps->top == 0)
	//	return true;
	//else
	//	return false;
	//�������εĴ�������������������
	return ps->top == 0;
	//��ʵ����뷵�ص���ps->top == 0�Ƚ�֮�����ֵ
}