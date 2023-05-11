#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Person{
public:
	Person(string name, int age) :m_Name(name), m_Age(age){

	}

	string m_Name;
	int m_Age;
};

void test1(){
	queue<Person>q;

	Person p1("����ǿ", 19);
	Person p2("������", 19);
	Person p3("����", 0);
	Person p4("����", 3);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "���еĴ�С�� " << q.size() << endl;

	//�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ����β������
	while (!q.empty()){
		//�鿴��ͷ
		cout << "��ͷԪ�� - ������ " << q.front().m_Name << " ���䣺 " << q.front().m_Age << endl;
		cout << "��βԪ�� - ������ " << q.back().m_Name << " ���䣺 " << q.back().m_Age << endl;
		cout << "------------------------------" << endl;

		//��ջ
		q.pop();
	}
	cout << "���еĴ�С�� " << q.size() << endl;
}

int main(){
	
	test1();
	return 0;
}