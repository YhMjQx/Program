//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class T1,class T2>
//class Person{
//public:
//	Person(T1 name, T2 age);
//
//	void ShowPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age){
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::ShowPerson(){
//	cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
//}

//#include"Person.h"

//第一种解决办法：
//该文件中包含#include"Person.cpp"
//#include"Person.cpp"
//为什么会出现这种问题呢？
//是因为类模板在包含的时候，其类中的成员函数并不会创建，要在调用的时候才会创建
//所以刚开始的时候单单包含一个Person.h是没用的，这样就会导致编译器链接的时候根本链接不上person.cpp
//以至于编译器编译的时候看不见函数的实现，就导致程序运行失败了
//所以直接包含.cpp文件即可，在.cpp文件中包含 .h文件就好了

//第二种解决办法：
//将声明和实现的代码放在同一个头文件当中，并且将文件名后缀改为.hpp
//而这种解决办法就比较简单了，将声明和实现放在一个文件当中，直接包含这个文件就完事了
#include"Person.hpp"

void test1(){
	Person<string, int>p("胡佳欣", 19);
	p.ShowPerson();
}

int main(){
	test1();
	return 0;
}