#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//ͳ��������������
void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	int num = count(v.begin(), v.end(), 5);
	cout << "���������� " << num << " �� 5" << endl;

}

class Person{
public:
	Person(string name, int age) :m_Name(name), m_Age(age){

	}

	bool operator==(const Person& p){
		if (this->m_Age == p.m_Age){
			return true;
		}
		else{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

void test2(){
	vector<Person>v;

	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	Person p("�����", 35);

	int num = count(v.begin(), v.end(), p);
	//��Ҫ���� == ����� ���ߵײ��������ͳ��
	cout << "���������� " << num << " ���������ͬ�����" << endl;

}

int main(){
	//test1();
	test2();
	return 0;

}