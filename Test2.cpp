#include<iostream>
using namespace std;


//对于一个没有任何接口的类，如果想要将它定义为抽象类，只能将虚析构函数定义为纯虚析构函数
//通常情况下在基类中的纯虚函数是不需要实现的，但是纯虚析构函数（只需用给出一个空的实现即可）就是个例外
class Base{
public:
	virtual ~Base() = 0
	{
		cout << "virtual ~Base() = 0" << endl;
	}
};

class Drived :public Base{

};
int main(){
	Drived d;
	return 0;
}