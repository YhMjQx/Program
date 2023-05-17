#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//统计内置数据类型
void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	int num = count(v.begin(), v.end(), 5);
	cout << "该容器中有 " << num << " 个 5" << endl;

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

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	Person p("诸葛亮", 35);

	int num = count(v.begin(), v.end(), p);
	//需要重载 == 运算符 告诉底层代码该如何统计
	cout << "该容器中有 " << num << " 个与诸葛亮同岁的人" << endl;

}

int main(){
	//test1();
	test2();
	return 0;

}