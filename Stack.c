#include"Stack.h"
void StackInit(ST* ps)
{
	ps->a = NULL;
	ps->top = 0;
	//ps->top = 0 -- 这种情况是先给值然后top再++，此时top指向的是栈顶再往后的一个位置
	//ps->top = -1 -- 这种情况是先给top++,然后再给值，此时top指向的是目前栈顶的位置
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
	//这里的top--就相当于顺序表里的size--，减掉栈里的数据个数
}
STDataType StackTop(ST* ps)//取栈顶的数据
{
	assert(ps);
	assert(!StackEmpty(ps));
	//相当于assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)//计算栈内部有多少个数据
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)//判断栈是否为空
{
	assert(ps);
	//if (ps->top == 0)
	//	return true;
	//else
	//	return false;
	//上面屏蔽的代码可用下面这句代码代替
	return ps->top == 0;
	//其实这代码返回的是ps->top == 0比较之后的真值
}