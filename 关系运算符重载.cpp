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
	Person p1("杨明强", 18);
	Person p2("胡佳欣", 18);

	if (p1 == p2){
		cout << "p1和p2是相等的" << endl;
	}
	else{
		cout << "p1和p2是不相等的" << endl;
	}

	if (p1 != p2){
		cout << "p1和p2是不相等的" << endl;
	}
	else{
		cout << "p1和p2是相等的" << endl;
	}
		

}

int main(){
	test1();
	
	return 0;
}