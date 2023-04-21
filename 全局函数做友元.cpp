#include<iostream>
#include<string>
using namespace std;

class Building{

public:
	//友元函数不是类的成员函数，声明可以放在类中的任何一个地方，如此，函数就可以访问到类的任何一个成员了
	friend void goodGay(Building* building);

	Building():m_SittingRoom("客厅"),m_BedRoom("卧室"){

	}

	string m_SittingRoom;//客厅

private:

	string m_BedRoom;//卧室

};

//全局函数
void goodGay(Building* building){
	cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;

	cout << "好基友全局函数 正在访问：" << building->m_BedRoom<< endl;

}

void test1(){
	Building building;
	goodGay(&building);

}
int main(){

	test1();
	return 0;
}