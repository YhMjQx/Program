#include<iostream>
#include<string>
using namespace std;

//���ʵ��
class Building;
class goodGay{
public:
	goodGay();

	void visit1();//��visit1���Է���Building��˽�г�Ա
		
	void visit2();//��visit2�����Է���Building��˽�г�Ա
		
private:
	Building* building;
};

class Building{
public:
	//���߱�������goodGay���µ�visit1��Ա������Ϊ����ĺ����ѣ����Է��ʱ����˽�г�Ա
	friend void goodGay::visit1();

	Building() :m_SittingRoom("����"), m_BedRoom("����"){

	}

	string m_SittingRoom;
private:
	string m_BedRoom;
};


//���еĳ�Ա�����Ķ���
goodGay::goodGay(){
	building = new Building;
}

void goodGay::visit1(){
	cout << "visit1�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit1�������ڷ��ʣ�" << building->m_BedRoom << endl;

}

void goodGay::visit2(){
	cout << "visit2�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	//cout << "visit2�������ڷ��ʣ�" << building->m_BedRoom << endl;

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