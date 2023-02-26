#include"SList.h"
void SLText1()
{
	SLNode* Plist = NULL;
	for (int i = 0; i < 5; i++)
	{
		SLPushBack(&Plist, i);
	}
	SLPrint(Plist);
	for (int i = 5; i < 10; i++)
	{
		SLPushFront(&Plist,i);
	}
	SLPrint(Plist);

}
void SLText2()
{
	SLNode* Plist = NULL;
	for (int i = 0; i < 5; i++)
	{
		SLPushBack(&Plist, i);
	}
	SLPrint(Plist);
	SLPopBank(&Plist);
	SLPrint(Plist);

}
int main()
{
	//SLText1();
	SLText2();
	return 0;
}