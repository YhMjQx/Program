//利用仿函数，可以改变排序规则
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
		//要求姓名和年龄都按照由小到大的顺序进行排序
		if (p1.m_Age == p2.m_Age){
			return p1.m_Name < p2.m_Name;
		}
		return p1.m_Age < p2.m_Age;
	}
};

void test1(){
	set<int>s1;

	//这种插入方式默认的是升序插入并排序
	s1.insert(10);
	s1.insert(50);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	//set容器插了数据之后就不能在进行改变了，所以就需要在插入之前给他指定插入方式
	for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//让插入之后就按降序排序该怎么办呢，这时候就要用到仿函数的办法了

	set<int,MyCompare>s2;//为什么这里的比较函数的方法一定要用用类包含，并且在类中包含呢，是因为<>这里面本来就应在存放类型
						//一般情况下，这是要用作返回类型的，所以当然得是类

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
	//对于自定义数据类型，必须要利用仿函数来指定排序规则，且仿函数要放在类中
	set<Person, PersonCompare>s;

	//创建人物对象
	Person p1("刘备", 24);
	Person p2("关羽", 28);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, PersonCompare>::const_iterator it = s.begin(); it != s.end(); ++it){
		cout << "姓名：" << it->m_Name << "  年龄：" << (*it).m_Age << endl;
	}
}

int main(){
	//test1();
	test2();
	return 0;
}