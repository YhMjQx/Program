#include<iostream>
using namespace std;

class Base{
public:
	static int m_A;

	static void func(){
		cout << "Base - static void func()" << endl;
	}

	static void func(int a){
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base{
public:
	static int m_A;

	static void func(){
		cout << "Son - static void func()" << endl;
	}


};
int Son::m_A = 200;

//同名的静态成员变量的处理方法
void test1(){
	Son s1;
	//1.通过对象访问
	cout << "通过对象访问：" << endl;
	cout << "Son 下 m_A = "<< s1.m_A << endl;
	cout << "Base 下 m_A = " << s1.Base::m_A << endl;

	cout << "通过类名访问：" << endl;
	cout << "Son 下 m_A = " << Son::m_A <<endl;
	//第一个::代表通过类名的方式访问  第二个::代表访问父类下的作用域
	//通过Son来访问父类作用域下的m_A
	cout << "Base 下 m_A = " << Son::Base::m_A << endl;
}


//同名静态成员函数的处理方法
void test2(){
	Son s;
	//通过对象访问静态成员函数
	cout << "通过对象访问静态成员函数:" << endl;
	s.func();
	s.Base::func();
	//通过类名访问静态成员函数
	cout << "通过类名访问静态成员函数:" << endl;
	Son::func();
	Son::Base::func();

	//子类出现和父类同名的静态成员函数，也会隐藏父类中所有同名的成员函数
	//如果想调用父类中被隐藏的同名成员函数，需要加作用域
	Son::Base::func(100);
}
int main(){
	test1();
	test2();
	return 0;
}