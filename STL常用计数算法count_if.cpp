#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Greater5(int val){
	return val > 5;

}

class Greater6{
public:
	bool operator()(int val){
		return val > 6;
	}
};

void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	int num = count_if(v.begin(), v.end(), Greater5);
	cout << "���������� " << num << " ������ 5 ������" << endl;

	num = count_if(v.begin(), v.end(), Greater6());
	cout << "���������� " << num << " ������ 6 ������"<<endl;

}

class Person{
public:
	Person(string name, int age){
		this->m_Age = age;
		this->m_Name = name;
	}

	string m_Name;
	int m_Age;

};

void test2(){
	//���Զ����������͵�ͳ��Ҳ��һ����
}

int main(){
	test1();
	test2();

	return 0;
}