//���÷º��������Ըı��������
#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person{
public:
	Person(string name, int age) :m_Name(name), m_Age(age){

	}

	string m_Name;
	int m_Age;
};

class MyCompare{
public:
	bool operator()(int v1,int v2){
		return v1 > v2;
	}

};

class PersonCompare{
public:
	bool operator()(const Person& p1, const Person& p2){
		//Ҫ�����������䶼������С�����˳���������
		if (p1.m_Age == p2.m_Age){
			return p1.m_Name < p2.m_Name;
		}
		return p1.m_Age < p2.m_Age;
	}
};

void test1(){
	set<int>s1;

	//���ֲ��뷽ʽĬ�ϵ���������벢����
	s1.insert(10);
	s1.insert(50);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	//set������������֮��Ͳ����ڽ��иı��ˣ����Ծ���Ҫ�ڲ���֮ǰ����ָ�����뷽ʽ
	for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//�ò���֮��Ͱ������������ô���أ���ʱ���Ҫ�õ��º����İ취��

	set<int,MyCompare>s2;//Ϊʲô����ıȽϺ����ķ���һ��Ҫ��������������������а����أ�����Ϊ<>�����汾����Ӧ�ڴ������
						//һ������£�����Ҫ�����������͵ģ����Ե�Ȼ������

	s2.insert(10);
	s2.insert(50);
	s2.insert(20);
	s2.insert(40);
	s2.insert(30);
	for (set<int>::iterator it = s2.begin(); it != s2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

}

void test2(){
	//�����Զ����������ͣ�����Ҫ���÷º�����ָ����������ҷº���Ҫ��������
	set<Person, PersonCompare>s;

	//�����������
	Person p1("����", 24);
	Person p2("����", 28);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, PersonCompare>::const_iterator it = s.begin(); it != s.end(); ++it){
		cout << "������" << it->m_Name << "  ���䣺" << (*it).m_Age << endl;
	}
}

int main(){
	//test1();
	test2();
	return 0;
}