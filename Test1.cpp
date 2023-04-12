#include<iostream>
using namespace std;


class ObjectB{
public:
	ObjectB(){
		cout << "ObjectB..." << endl;
	}
	ObjectB(int b) :objb_(b){

	}
	~ObjectB(){
		cout << "~ObjectB..." << endl;
	}
	int objb_;
};

class ObjectD{
public:
	ObjectD(){

	}
	ObjectD(int d): objd_(d){
		cout << "ObjectD..." << endl;
	}
	~ObjectD(){
		cout << "~ObjectD..." << endl;
	}
	int objd_;
};

class Base{
public:
	Base(){
		cout << "Base..." << endl;
	}
	Base(int b) :b_(b){
		cout << "Base..." << endl;
	}
	//拷贝构造函数，将该类的成员们都在初始化列表中进行初始化是较好的
	Base(const Base& other) :objb_(other.objb_), b_(other.b_)
	{

	}
	~Base(){
		cout << "~Base..." << endl;
	}
	int b_;
	ObjectB objb_;
};

class Derived :public Base{
public:
	Derived(int b,int d) :d_(d), Base(b),objd_(222)
	{
		cout << "Derived..." << endl;
	}

	//拷贝构造函数和普通构造函数的初始化列表应该是差不多的，例如参数个数，参数类型
	Derived(const Derived& other) :d_(other.d_), objd_(other.objd_), Base(other)
	{
		
	}
	~Derived(){
		cout << "~Derived..." << endl;
	}
	int d_;
	ObjectD objd_;
};

int main(){
	Derived d1(39,93);
	//不管如何，都会先构造Base类的对象，然后在构造派生类对象
	cout << "Base - " << d1.b_ <<endl<< "Derived - " << d1.d_ << endl;

	Base b1(100);
	Base b2(b1);
	cout << b2.b_ << endl;


	//Derived d2(d1);
	return 0;
}
//不管新类是如何调用旧类的对象成员，如果旧类没有默认构造函数，那么就必须在新类的构造函数的初始化列表中对其进行初始化