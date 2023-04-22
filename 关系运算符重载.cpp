#include<iostream>
using namespace std;

class Person{
public:
	Person(string name,int age):m_Name(name),m_Age(age){

	}

	bool operator==(Person& p){
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name){
			return true;
		}
		else
			return false;
	}

	bool operator!=(Person& p){
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name){
			return false;
		}
		else
			return true;
	}

	string m_Name;
	int m_Age;
};

void test1(){
	Person p1("����ǿ", 18);
	Person p2("������", 18);

	if (p1 == p2){
		cout << "p1��p2����ȵ�" << endl;
	}
	else{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}

	if (p1 != p2){
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
	else{
		cout << "p1��p2����ȵ�" << endl;
	}
		

}

int main(){
	test1();
	
	return 0;
}