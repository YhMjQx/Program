#include<iostream>
#include<map>
using namespace std;

//map����Ĭ���������Ϊ����keyֵ���д�С��������������θı��������ͨ���º��������Ըı��������
//ע����һ�㣬Ҫ��ʹ���Լ���������������ô�Լ�������������һ��Ҫ����ǰ��
class MyCompare{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

void Printmap(map<int, int, MyCompare>& m){
	for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "keyֵ��" << (*it).first << " valueֵ��" << it->second << endl;
	}
	cout << "---------------------" << endl;
}


void test1(){
	//����һ��map����
	map<int,int,MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	
	//for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); ++it){
	//	cout << "keyֵ��" << (*it).first << " valueֵ��" << it->second << endl;
	//}
	Printmap(m);
}

int main(){
	test1();

	return 0;
}