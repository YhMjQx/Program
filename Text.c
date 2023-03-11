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
	//前插两个
	PushFront(plist, 5);
	PushFront(plist, 5);
	ListPrint(plist);

	//尾插两个
	PushBack(plist, 4);
	PushBack(plist, 4);
	ListPrint(plist);

	//删掉链表中数据第一个为2的节点
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
//顺序表的优点：
//1.可以用下标访问，也就是支持随机访问，需要随机访问结构的算法（排序，二分查找）可以很好地适用
//2.cpu高速缓存命中率更高
//顺序表的缺点：
//1.投不中不插入和删除时效率低
//2.连续的物理空间，空间不够了需要增容
//（a.增容有一定的消耗 b.为了避免频繁的增容，一般我们都会按照倍数去增容，但这样用不完就会造成空间浪费）
//
//
//链表（双向带头循环链表）
//优点：1.任意位置插入删除效率高 - O(1)
//      2.按需申请释放空间
//缺点：1.不支持随机访问（用下标访问）意味着一些排序，二分查找的算法在这种结构上不适用
//      2.链表存储一个值，同时还要存链接指针，但也有一定的作用，严格来说并不能算做什么缺点
//      3.CPU高速缓存命中率更低