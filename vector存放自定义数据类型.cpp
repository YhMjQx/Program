#include<iostream>
#include<vector>
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
	vector<Person>v;
	Person p1("ymq", 19);
	Person p2("hjx", 19);
	Person p3("hy1", 3);
	Person p4("hy2", 2);
	Person p5("hy3", 1);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//用迭代器遍历数组
	for (vector<Person>::iterator it = v.begin(); it < v.end(); ++it){
		//cout << "姓名： " << (*it).m_Name << " 年龄： " << (*it).m_Age << endl;
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}

}


//存放自定义数据类型指针
void test2(){
	vector<Person*>v;
	Person p1("ymq", 19);
	Person p2("hjx", 19);
	Person p3("hy1", 3);
	Person p4("hy2", 2);
	Person p5("hy3", 1);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it < v.end(); ++it){
		cout << "姓名： " << (*it)->m_Name << " 年龄： " << (*it)->m_Age << endl;
	}
}

int main(){
	//test1();
	test2();

	return 0;
}