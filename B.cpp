#include "B.h"
//但是尽管B.h头文件中对A用了前向声明，但是在B.cpp文件中，如果要用到A类的话，依旧要包含A.h
#include"A.h"

B::B()
{
}


B::~B()
{
}
