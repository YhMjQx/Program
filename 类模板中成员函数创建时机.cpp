#include<iostream>
#include<string>
using namespace std;

//普通类中的成员函数一开始就可以创建
//类模板中的成员函数在调用时才创建
class Person1{
public:
	void ShowPerson1(){
		cout << "Person1 show" << endl;
	}
};

class Person2{
public:
	void ShowPerson2(){
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass{
public:
	T obj;
	//无法确定obj的具体类型，所以该模板类的成员函数在一开始不会去创建

	void func1(){
		obj.ShowPerson1();
	}

	void func2(){
		obj.ShowPerson2();
	}
};

void test1(){
	MyClass<Person1> p1;
	p1.func1();
	//p1.func2(); - 这两段代码在调用的时候才去创建类模板中成员函数

	MyClass<Person2> p2;
	//p2.func1();
	p2.func2();
}

int main(){

	test1();
	return 0;
}