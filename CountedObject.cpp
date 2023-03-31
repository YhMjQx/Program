#include "CountedObject.h"

int CountedObject::count_ = 0;	//静态成员的定义性声明，此时才能初始化,没有初始化，默认值为0
CountedObject::CountedObject()
{
	++count_;
}


CountedObject::~CountedObject()
{
	--count_;
}


int CountedObject::GetCount(){
	return count_;
}
