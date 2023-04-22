#include<iostream>
using namespace std;
//如果类中有成员指向堆区，做赋值操作时应该用到深拷贝

class Person{
public:
	Person(int age) :m_Age(new int(age)){

	}

	~Person(){
		if (m_Age != NULL){
			delete m_Age;
		}
	}

	//重载赋值运算符
	Person& operator=(Person& p){
		//注意，我们应该先看本类当中原本是否存储的有数据，如果有的话，我们应该先释放干净，然后在进行深拷贝
		if (m_Age != NULL){
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;//应该返回自身,目的为了能实现链式编程的操作
	}

//private:
	int* m_Age;
};

void test1(){
	Person p1(39);
	Person p2(18);
	Person p3(25);

	p3 = p2 = p1;

	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;

	//如果只是简单的调用系统提供的默认赋值运算符（浅拷贝），那么会将m_Age这个指针的值完完全全拷贝给另一个对象的指针
	//当两个对象销毁调用析构函数的时候，就会对同一块空间进行两次重复的释放，这样就会导致运行崩溃
	//此时就要自己重载等号运算符，重载为深拷贝
}

int main(){

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//a = b = c;
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	//那么，我们实现的赋值运算符重载也应该具有这样的功能

	test1();
	return 0;
}