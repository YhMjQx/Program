#include"SeqList.h"
void TextSeqList1()
{
	SL s1;
	SeqListInit(&s1);

	//尾增5个数据
	for (int i = 1; i <= 5; i++)
	{
		SeqListPushBank(&s1, i);
	}
	SeqListPrint(&s1);

	//尾删两个数据
	SeqListPopBank(&s1);
	SeqListPopBank(&s1);

	SeqListPrint(&s1);

	SeqListDestory(&s1);
}

TextSeqList2()
{
	SL s1;
	SeqListInit(&s1);

	//尾增4个数据
	for (int i = 1; i <= 4; i++)
	{
		SeqListPushBank(&s1, i);
	}
	SeqListPrint(&s1);
	
	//头增数据
	SeqListPushFront(&s1, -1);
	SeqListPrint(&s1);

	//头删数据
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