#include<iostream>
#include<list>
#include<string>
using namespace std;

//将Person自定义数据类型进行排序，Person中属性有姓名，年龄，身高
//排序规则：按照年龄进行升序，如果年龄相同，按照身高进行降序

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
		cout << "姓名：" << (*it).m_Name << "  年龄：" << it->m_Age << "  身高：" << it->m_Height << endl;
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
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 160);
	Person p6("关羽", 35, 200);

	//插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	cout << "排序前的结果：" << endl;
	PrintPerson(L);


	//排序
	cout << "--------------------------------" << endl;
	cout << "排序后的结果：" << endl;
	L.sort(ComparePerson);//单单只是调用sort是不行的，因为这个成员函数sort是无法自己识别到底是根据年龄，还是身高，还是体重来判断的
				//这个时候就需要我们自己手动来提供比较方法
	PrintPerson(L);


}

int main(){
	test1();
	return 0;
}