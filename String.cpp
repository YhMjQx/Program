#include "String.h"
//浅拷贝就相当于赋值运算，在这里比如 对象1.str_ = 对象2.str_;
//那么这里就会导致最后程序结束调用析构函数的时候，会对str_所在的空间销毁释放两次，这就出问题了
String::String(char* str)
{
	 str_ = AllocAndCpy(str);
}

String::~String()
{
	//由于在堆上开辟了空间，所以在析构函数中才用到delete
	delete[] str_;
}

char* String::AllocAndCpy(const char* str){
	int len = strlen(str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display() const{
	cout << str_ << endl;
}

String::String(const String& other){
		//在这里就不能在函数定义时进行初始化，因为如果在函数上进行初始化这种情况也属于调用了浅拷贝
		//String::String(const String& other) :str_(other.str_); - Error 这种情况也属于调用了浅拷贝
		//所以就使用深拷贝
	str_ = AllocAndCpy(other.str_);
}


String& String::Assign(const char* str){
	delete[] str_;
	str_ = AllocAndCpy(str);
	return *this;
}


String& String:: operator=(const String& other)//自己的等号运算符
{
	if (this == &other)
		return *this;

		//既然在使用“=”运算符，说明=左边的对象已经存在了，存在了之后才能赋值不是吗，所以我要赋值的地方已经被占用了
		//就需要先把原来的等号左边的空间释放了，再调用自己的深拷贝构造函数
	return Assign(other.str_);
}


String& String::operator=(const char* str){
		//由于在这里，就是对象给对象赋值了，而是直接将一段字符串赋值给已创建的对象
		//所以就不需要判断，this指针指向的是否和所传实参一样，
		//但是有一点还是一样的，就是得先把等号左边已经存储过数据的空间中的数据释放掉
	return Assign(str);
}

bool String::operator!() const{
	return (strlen(str_) != 0);
}

//
char& String::operator[](unsigned int index){
		//return str_[index];
		//一般情况下，如果两个函数的函数体大相径庭，我们并不需要实现两个版本的函数，会导致代码冗余，那么我们该如何处理呢
		//我们可以让non const版本来调用const版本,就可以避免代码很多的情况下做成的困难
	return const_cast<char&>(static_cast<const String&>(*this)[index]);
		//*this - 指向这个类的隐藏指针，我需要将这个类转化成const类型的类，以便调用const operator[]函数
		//static_ cast<const String&>(*this) - 将*this这个类转化成const 类型的类
		//const_cast<char&>(static_cast<const String&>(*this)) - 将const类型的类的返回值去掉常量性，因为该函数本身是返回的non const
}

const char& String::operator[](unsigned int index) const{
	return str_[index];
}
//

String operator+(const String& s1, const String& s2){
	//int len = strlen(s1.str_) + strlen(s2.str_) + 1;
	//char* newstr = new char[len];
	//memset(newstr, 0, len);
	//strcpy(newstr, s1.str_);
	//strcat(newstr, s2.str_);
	//	//这里的newstr是在函数内部创建的临时对象，而且newstr的空间是在堆上创建出来的，必须要释放
	//	//况且newstr出栈是会被销毁的，那么就根本无法正确返回，所以我就必须将其赋值给另一个新的类，然后将其销毁
	//	//最后我直接返回被复制的这个类
	//String tmp(newstr);//这里是调用拷贝构造函数，将newstr赋给了tmp，所以尽管我将newstr释放了，但是tmp里的数据依旧存在依旧
	//delete[] newstr;
	//return tmp;
	String str = s1;
	str += s2;
	return str;
}


String& String::operator+=(const String& other){
	int len = strlen(str_) + strlen(other.str_) + 1;
	char* newstr = new char[len];
	memset(newstr, 0, len);
	strcpy(newstr, str_);
	strcat(newstr, other.str_);

	delete[] str_;
	str_ = newstr;
	//这里千万不敢释放销毁newstr，不释放newstr的原因是因为我将newstr的内容都付给了str_，意思是newstr和str_这两个指针相等
	//这两个指针都指向同一块空间，在程序结束的时候系统会调用析构函数，对str_进行释放销毁，如果我在函数里面就销毁了
	//那么整个程序就会对str_这片空间销毁两次，这就会出问题，就算不从者方面考虑，那么我们换个方向看
	//str_和newstr两个指针指向的是同一片空间，我释放newstr也就相当于释放了str_，那我还用什么，对不对，
	return *this;//返回自身，也和返回类型为引用相匹配
}


ostream& operator<<(ostream& os, const String& str){
	os << str.str_;
	return os;
}


istream& operator>>(istream& is, String str){// >>(提取符)
	char tmp[1024];
	cin >> tmp;//cin - 输入，相当于C语言中的scanf
	str = tmp;//tmp出栈会自动销毁的，我们不需用管
	return is;
}
