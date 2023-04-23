#include<iostream>
using namespace std;
//多继承可能会引发父类中有同名成员出现，需要加作用域区分
//C++实际开发中不建议用多继承

class Base1{
public:
	Base1(/*int a*/){
		m_A = 100;
	}
	int m_A;
};

class Base2{
public:
	Base2(/*int b*/){
		m_A = 200;
	}
	int m_A;
};

//子类 虚继承Base1和Base2
class Son :public Base1, public Base2{
public:
	Son(int c,int d):m_C(c),m_D(d){

	}
	int m_C;
	int m_D;
};

void Test1(){
	Son s(300,400);
	cout << "sizeof(s) = " << sizeof(s) << endl;
	cout << "Base1::m_A = " << s.Base1::m_A << endl;
	cout << "Base2::m_A = " << s.Base2::m_A << endl;

}

int main(){
	Test1();
	return 0;
}