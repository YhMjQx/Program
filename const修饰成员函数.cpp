//常函数：
//成员函数后加const，我们称这个函数为常函数
//常函数不可以修改成员变量
//成员变量声明时，加关键字mutable，在场函数中依然可以被改变
//
//常对象：
//声明对象前加const的对象
//常对象只能调用常函数
#include<iostream>
using namespace std;

class Person{
public:
	//this指针的本质 ： 是一个指针常量，指针的值是无法改变的
	//在该类就相当于Person* const this
	//为了让this指针指向的内容也无法改变，我们需将再加一个const
	//const Person* const this
	//那么这个const对应在韩式的那个位置合适呢，那就是函数的最后
	void ShowPerson() const {
		//现在这是一个常函数，在该函数体内是无法对成员变量进行改变的
		////this = NULL;这是无法操作的
		////m_A = 39;这是无法操作的

		this->m_B = 39;
	}

	void func(){
		cout << "void func()" << endl;
	}
private:
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值,关键字mutable
};

int main(){
	//常对象
	const Person p1;//在对象前用const修饰,常对象是不允许修改成员变量，但是特殊成员变量还是可以修改的
	p1.ShowPerson();
	//p1.func();常对象只能调用常函数，不能调用普通成员函数，因为普通成员函数是可以修改成员变量的
	return 0;
}