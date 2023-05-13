#include<iostream>
#include<list>
#include<string>
using namespace std;

//��Person�Զ����������ͽ�������Person�����������������䣬���
//������򣺰�����������������������ͬ��������߽��н���

class Person{
public:

	Person(string name,int age,int height) :m_Name(name), m_Age(age), m_Height(height){

	}

	string m_Name;
	int m_Age;
	int m_Height;
};

void PrintPerson(list<Person>& L){
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << "������" << (*it).m_Name << "  ���䣺" << it->m_Age << "  ��ߣ�" << it->m_Height << endl;
	}
}

bool ComparePerson(Person& p1,Person& p2){
	if (p1.m_Age == p2.m_Age){
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}

void test1(){
	list<Person>L;
	Person p1("����", 35, 175);
	Person p2("�ܲ�", 45, 180);
	Person p3("��Ȩ", 40, 170);
	Person p4("����", 25, 190);
	Person p5("�ŷ�", 35, 160);
	Person p6("����", 35, 200);

	//��������
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	cout << "����ǰ�Ľ����" << endl;
	PrintPerson(L);


	//����
	cout << "--------------------------------" << endl;
	cout << "�����Ľ����" << endl;
	L.sort(ComparePerson);//����ֻ�ǵ���sort�ǲ��еģ���Ϊ�����Ա����sort���޷��Լ�ʶ�𵽵��Ǹ������䣬������ߣ������������жϵ�
				//���ʱ�����Ҫ�����Լ��ֶ����ṩ�ȽϷ���
	PrintPerson(L);


}

int main(){
	test1();
	return 0;
}