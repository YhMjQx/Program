#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//find(iterator beg,iterator end,value);//����Ԫ��
//����ָ��Ԫ�أ��ҵ��ͷ���ָ��Ԫ�ص��������Ҳ����ͷ��ؽ���������

//find_if(iterator beg,iterator end,pred)//����������Ԫ��
//����ָ��Ԫ�أ��ҵ��ͷ���ָ��Ԫ�ص��������Ҳ����ͷ��ؽ��������������ҿ��԰���ν�ʵķ�ʽ���в���

//adjacent_find()//���������ظ�Ԫ��
//binary_search()//���ֲ��ҷ�
//count()//ͳ��Ԫ�ظ���
//count_if()//������ͳ��Ԫ�ظ���

void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end()){
		cout << "not find" << endl;
	}
	else{
		cout << "find succefuly " << *it << endl;
	}
}

class Person{
public:
	Person(string name, int age) :m_Name(name), m_Age(age){

	}

	bool operator == (const Person& p){
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name){
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
	Person p1("������", 19);
	Person p2("����ǿ", 19);
	Person p3("����", 0);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	Person pp("������", 19);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	//ϵͳ���޷���֪����αȽ��Զ����������͵ģ������Ҫ�����Լ��ֶ����� ==
	if (it == v.end()){
		cout << "����ʧ��" << endl;
	}
	else{
		cout << "���ҳɹ� " << " ������" << it->m_Name << " ���䣺" << it->m_Age << endl;
	}

}

//bool GreaterFive(int val){
//	return val > 5;
//}

class GreaterFive{
public:
	bool operator()(int val){
		return val > 5;
	}
};

void test3(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	
	for (vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive()); it != v.end(); ++it){
		
		cout << *it << " ";
	}
	cout << endl;

}

class FindGreaterFive{
public:
	bool operator()(Person& p){
		return p.m_Age < 19;
	}
};

void test4(){
	vector<Person> v;
	Person p1("������", 19);
	Person p2("����ǿ", 19);
	Person p3("����1", 1);
	Person p4("����2", 2);
	Person p5("����3", 3);


	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	
	for (vector<Person>::iterator it = find_if(v.begin(), v.end(), FindGreaterFive()); it != v.end(); ++it){
		cout << "������" << it->m_Name << "   ���䣺" << it->m_Age << endl;
	}
	

}

int main(){
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}