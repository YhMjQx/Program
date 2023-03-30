#include "String.h"

String::String(char* str)
{
	 str_ = AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

char* String::AllocAndCpy(char* str){
	int len = strlen(str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display(){
	cout << str_ << endl;
}

String::String(const String& other){
	//在这里就不能在函数定义时进行初始化，因为如果在函数上进行初始化这种情况也属于调用了浅拷贝
	//String::String(const String& other) :str_(other.str_); - Error 这种情况也属于调用了浅拷贝
	str_ = AllocAndCpy(other.str_);
}

String& String:: operator=(const String& other)//自己的等号运算符
{
	if (this == &other)
		return *this;

	//既然在使用“=”运算符，说明=左边的对象已经存在了，那么我要赋值的
	//就需要先把原来的等号左边的空间释放了，再调用自己的深拷贝构造函数
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

