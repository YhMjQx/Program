#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//find(iterator beg,iterator end,value);//查找元素
//查找指定元素，找到就返回指定元素迭代器，找不到就返回结束迭代器

//find_if(iterator beg,iterator end,pred)//按条件查找元素
//查找指定元素，找到就返回指定元素迭代器，找不到就返回结束迭代器，并且可以按照谓词的方式进行查找

//adjacent_find()//查找相邻重复元素
//binary_search()//二分查找法
//count()//统计元素个数
//count_if()//按条件统计元素个数

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
	Person p1("胡佳欣", 19);
	Person p2("杨明强", 19);
	Person p3("胡杨", 0);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	Person pp("胡佳欣", 19);

	vector<Person>::iterator it = find(v.begin(), v.end(), pp);
	//系统是无法得知该如何比较自定义数据类型的，因此需要我们自己手动重载 ==
	if (it == v.end()){
		cout << "查找失败" << endl;
	}
	else{
		cout << "查找成功 " << " 姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
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
	Person p1("胡佳欣", 19);
	Person p2("杨明强", 19);
	Person p3("胡杨1", 1);
	Person p4("胡杨2", 2);
	Person p5("胡杨3", 3);


	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	
	for (vector<Person>::iterator it = find_if(v.begin(), v.end(), FindGreaterFive()); it != v.end(); ++it){
		cout << "姓名：" << it->m_Name << "   年龄：" << it->m_Age << endl;
	}
	

}

int main(){
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}