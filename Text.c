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
	//��ô��������ӡջ�����������
	//�����ʼ�Ҷ����top��0����������ҵ�top��ʾ����ջ�����ݵĸ����������ܳ䵱�±�ʹ�ã���Ϊ��ʱ��top���±��һ
	//������Ӧ��ѡ������top��һ��Ȼ����top=0��ʱ�������ѭ�����ӡ����
	//��Ȼ����Ҳ����ѡ���ʼ��top=-1�������������ͽ���ˣ������ֻ��������������
	st.top -= 1;
	while (!StackEmpty(&st))
	{
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
	while (*s)
	{
		//������������ַ������ַ��������žͽ�ջ
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st,*s);
			++s;
		}
		//������������ַ���������ַ����������ţ����������ţ���������Ҫ����ջ��������
		//��ջ�����ڴ�ʱ���������������ַ����бȽ�
		else
		{
			//��ʱҪ�жϣ�����ս�������һ�������ŵĻ���ʱջ��Ϊ��StackEmpty(&st)������ֵ����ʱ����û����������������ƥ�䣬���Է���false
			if (StackEmpty(&st))
			{
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