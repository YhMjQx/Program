#include<iostream>
#include<string>
using namespace std;

//������Ԫ
class Building{
public:
	friend class goodGay;
	Building() :m_SittingRoom("����"), m_BedRoom("����"){

	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};


class goodGay{
public:
	//�������������
	goodGay(){
		building = new Building;
	}

	void visit(){
		cout << "�û������ڷ��ʣ� " << building->m_SittingRoom << endl;
		cout << "�û������ڷ��ʣ� " << building->m_BedRoom << endl;

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