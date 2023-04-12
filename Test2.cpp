#include<iostream>
using namespace std;

class Base{
public:
	Base() :x_(0){
	}

	int GetBaseX() const{
		return x_;
	}

	void Show(){
		cout << "Base::Show..." << endl;
	}

	int x_;
};

//派生类，这里的x_和基类的x_不一样
//派生类的x_与基类的x_重定义的时候，如果用派生类来访问数据成员，那么会访问到派生类的数据成员
class Derived : public Base{
public:
	Derived() :x_(0){

	}

	int GetDerivedX() const{
		return x_;
	}

	void Show(int n){
		cout << "Derived::Show..." << endl;
	}

	void Show(){
		cout << "Derived::Show..." << endl;

	}
	int x_;
};

int main(){

	Derived d;
	d.x_ = 39;
	d.Base::x_ = 93;//想要访问基类当中的数据成员就得这么写
	cout << d.GetBaseX() << endl;
	cout << d.GetDerivedX() << endl;

	d.Show();
	d.Show(0);
	d.Base::Show();//想要访问基类中的成员函数就要这么写
	return 0;
}