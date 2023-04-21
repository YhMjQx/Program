#include<iostream>
#include<string>
using namespace std;

//类做友元
class Building{
public:
	friend class goodGay;
	Building() :m_SittingRoom("客厅"), m_BedRoom("卧室"){

	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};


class goodGay{
public:
	//创建建筑物对象
	goodGay(){
		building = new Building;
	}

	void visit(){
		cout << "好基友正在访问： " << building->m_SittingRoom << endl;
		cout << "好基友正在访问： " << building->m_BedRoom << endl;

	}
private:
	Building* building;
};



void test1(){
	goodGay gg;
	gg.visit();
}

int main(){
	test1();
	return 0;
}