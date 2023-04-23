#include<iostream>
using namespace std;

class Base{
public:
	Base(){
		cout << "Base构造函数" << endl;
	}

	~Base(){
		cout << "Base的析构函数" << endl;
	}
};

class Son : public Base{
public:
	Son(){
		cout << "Son构造函数" << endl;
	}

	~Son(){
		cout << "Son的析构函数" << endl;
	}
};

void Test1(){
	//Base b;
	Son s;
}

int main(){
	Test1();
	//先有父类才有的子类，和让一个类作为另一个类的成员有点像
	return 0;
}