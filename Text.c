#include"DList.h";
void TextList1()
{
	LTNode* plist = ListInit();
	for (int i = 0; i < 5; i++)
	{
		PushBack(plist, i);
	}
	ListPrint(plist);
	PopBack(plist);
	ListPrint(plist);
	PushFront(plist, 9);
	ListPrint(plist);
	//ǰ������
	PushFront(plist, 5);
	PushFront(plist, 5);
	ListPrint(plist);

	//β������
	PushBack(plist, 4);
	PushBack(plist, 4);
	ListPrint(plist);

	//ɾ�����������ݵ�һ��Ϊ2�Ľڵ�
	LTNode* pos = ListFind(plist, 2);
	ListErase(pos);
	ListPrint(plist);
	//ListDestroy(plist);
	//plist = NULL;
}
int main()
{
	TextList1();
	return 0;
}
//˳�����ŵ㣺
//1.�������±���ʣ�Ҳ����֧��������ʣ���Ҫ������ʽṹ���㷨�����򣬶��ֲ��ң����Ժܺõ�����
//2.cpu���ٻ��������ʸ���
//˳����ȱ�㣺
//1.Ͷ���в������ɾ��ʱЧ�ʵ�
//2.����������ռ䣬�ռ䲻������Ҫ����
//��a.������һ�������� b.Ϊ�˱���Ƶ�������ݣ�һ�����Ƕ��ᰴ�ձ���ȥ���ݣ��������ò���ͻ���ɿռ��˷ѣ�
//
//
//����˫���ͷѭ������
//�ŵ㣺1.����λ�ò���ɾ��Ч�ʸ� - O(1)
//      2.���������ͷſռ�
//ȱ�㣺1.��֧��������ʣ����±���ʣ���ζ��һЩ���򣬶��ֲ��ҵ��㷨�����ֽṹ�ϲ�����
//      2.����洢һ��ֵ��ͬʱ��Ҫ������ָ�룬��Ҳ��һ�������ã��ϸ���˵����������ʲôȱ��
//      3.CPU���ٻ��������ʸ���