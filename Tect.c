#include"SeqList.h"
void TextSeqList1()
{
	SL s1;
	SeqListInit(&s1);

	//β��5������
	for (int i = 1; i <= 5; i++)
	{
		SeqListPushBank(&s1, i);
	}
	SeqListPrint(&s1);

	//βɾ��������
	SeqListPopBank(&s1);
	SeqListPopBank(&s1);

	SeqListPrint(&s1);

	SeqListDestory(&s1);
}

TextSeqList2()
{
	SL s1;
	SeqListInit(&s1);

	//β��4������
	for (int i = 1; i <= 4; i++)
	{
		SeqListPushBank(&s1, i);
	}
	SeqListPrint(&s1);
	
	//ͷ������
	SeqListPushFront(&s1, -1);
	SeqListPrint(&s1);

	//ͷɾ����
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListDestory(&s1);
}
int main()
{
	//TextSeqList1();
	TextSeqList2();
}