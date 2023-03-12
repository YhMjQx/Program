#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<errno.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//类似于顺序表中的size，也就是栈里目前的数据个数
	int capacity;
}ST;
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);//取栈顶的数据
int StackSize(ST* ps);//计算栈内部有多少个数据
bool StackEmpty(ST* ps);//判断栈是否为空