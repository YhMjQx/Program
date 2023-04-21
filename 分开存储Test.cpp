#include<iostream>
using namespace std;

class Person{
	int m_A;//非静态成员变量，属于类的对象上
	static int m_B;//静态成员变量，不属于类的对象上

	void func(){} //非静态成员函数，不属于类的对象上
	static void func2(){} //静态成员函数，不属于类的对象上
};
int Person::m_B = 0;
int main(){
	//如果一个类是空类，那么系统还是会分配一个字节的空间给这个类，好便于区分空对象占内存的位置
	//每个空对象也应该有一个独一无二的内存地址
	cout << "Person类的大小为： " << sizeof(Person) << endl;

	return 0;
}