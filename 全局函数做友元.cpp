#include<iostream>
#include<string>
using namespace std;

class Building{

public:
	//��Ԫ����������ĳ�Ա�������������Է������е��κ�һ���ط�����ˣ������Ϳ��Է��ʵ�����κ�һ����Ա��
	friend void goodGay(Building* building);

	Building():m_SittingRoom("����"),m_BedRoom("����"){

	}

	string m_SittingRoom;//����

private:

	string m_BedRoom;//����

};

//ȫ�ֺ���
void goodGay(Building* building){
	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;

	cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom<< endl;

}

void test1(){
	Building building;
	goodGay(&building);

}
int main(){

	test1();
	return 0;
}