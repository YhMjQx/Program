#include<iostream>
using namespace std;
 
class Base{
public:
	int x_;
protected:
	//可以在派生类中访问
	int y_;
private:
	//即使是在派生类中也不能访问
	int z_;
};

//公有继承
class PublicInherit : public Base{
public:
	void Test(){
		x_ = 10;
		y_ = 20;
		//z_ = 30;//z_在基类中是private，那么在公有继承中派生类不能直接访问原基类的private成员
	}
private:
	int a_;
};

//私有继承
//基类中的公有和保护成员在派生类中都变成了私有的,相当于x_和y_在派生类中是private:
class PrivateInherit : private Base{
public:
	void Test(){
		x_ = 10;
		y_ = 20;
		//z_ = 30;// - error
	}
protected:

private:

};

//保护继承
//基类中的public数据成员在派生类中是protected成员，而基类中的protected数据成员在派生类中性质也是protected
//基类中的private数据成员在派生类中是不可直接访问的
int main(){

	return 0;
}