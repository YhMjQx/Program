#include<iostream>
#include<string>
using namespace std;

//类的实现
class Building;
class goodGay{
public:
	goodGay();

	void visit1();//让visit1可以访问Building中私有成员
		
	void visit2();//让visit2不可以访问Building中私有成员
		
private:
	Building* building;
};

class Building{
public:
	//告诉编译器，goodGay类下的visit1成员函数作为本类的好朋友，可以访问本类的私有成员
	friend void goodGay::visit1();

	Building() :m_SittingRoom("客厅"), m_BedRoom("卧室"){

	}

	string m_SittingRoom;
private:
	string m_BedRoom;
};


//类中的成员函数的定义
goodGay::goodGay(){
	building = new Building;
}

void goodGay::visit1(){
	cout << "visit1函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit1函数正在访问：" << building->m_BedRoom << endl;

}

void goodGay::visit2(){
	cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
	//cout << "visit2函数正在访问：" << building->m_BedRoom << endl;

}

void test1(){
	goodGay gg;
	gg.visit1();
}

void test2(){
	goodGay gg;
	gg.visit2();
}
int main(){
	test1();
	test2();
	return 0;
}