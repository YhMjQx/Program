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

	Person p1("杨明强", 19);
	Person p2("胡佳欣", 19);
	Person p3("胡杨", 0);
	Person p4("三九", 3);

	//入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列的大小： " << q.size() << endl;

	//判断只要队列不为空，查看对头，队尾，出队
	while (!q.empty()){
		//查看对头
		cout << "对头元素 - 姓名： " << q.front().m_Name << " 年龄： " << q.front().m_Age << endl;
		cout << "队尾元素 - 姓名： " << q.back().m_Name << " 年龄： " << q.back().m_Age << endl;
		cout << "------------------------------" << endl;

		//出栈
		q.pop();
	}
	cout << "队列的大小： " << q.size() << endl;
}

int main(){
	
	test1();
	return 0;
}