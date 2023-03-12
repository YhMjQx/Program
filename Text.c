#include"Stack.h"
StackText()
{
	ST st;
	StackInit(&st);
	for (int i = 0; i < 5; i++)
	{
		StackPush(&st, i);
	}
	//StackPop(&st);
	//StackPop(&st);
	//怎么遍历并打印栈里面的数据呢
	//由于最开始我定义的top是0，所以最后我的top表示的是栈里数据的个数，并不能充当下标使用，因为此时的top比下标大一
	//所以我应该选择先让top减一，然后让top=0的时候独自在循环外打印出来
	//当然，我也可以选择最开始让top=-1，这样这个问题就解决了，但是又会带来其他的问题
	st.top -= 1;
	while (!StackEmpty(&st))
	{
		printf("%d ", st.a[st.top]);
		StackPop(&st);
	}
	printf("%d", st.a[st.top]);
	StackDestroy(&st);
}
//OJ题：有效的括号
//给定一个只包括'(', ')', '[', ']', '{', '}'的字符串s，判断字符串是否有效
//有效字符串需满足：左括号必须用相同类型的右括号闭合；左括号必须以正确的顺序闭合
bool isValid(char* s)//当然，要能有效地使用这个函数，必须将STDatatype定义为char
{
	ST st;
	StackInit(&st);
	while (*s)
	{
		//如果遍历到的字符串的字符是左括号就进栈
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st,*s);
			++s;
		}
		//如果遍历到的字符串数组的字符不是左括号，而是右括号，则现在需要将进栈的左括号
		//出栈并且于此时遍历到的右括号字符进行比较
		else
		{
			//此时要判断，如果刚进来就是一个右括号的话此时栈中为空StackEmpty(&st)返回真值，此时根本没有左括号与右括号匹配，所以返回false
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			//用top接收左括号出栈
			STDataType top = StackTop(&st);
			//出栈了之后，用stackPop将栈里的数据个数减一		
			StackPop(&st);
			//现在进行比较,如果没有匹配上，就返回false,反之匹配上了就让s++
			if ((*s == ')'&&top != '(')
				|| (*s == ']'&&top != '{')
				|| (*s == '}'&&top != '{'))
			{
				StackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
		//如果栈中不为空，说明此时stackEmpty(&st)返回值为假，此时栈中还有左括号未与右括号匹配，此时应该返回false
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