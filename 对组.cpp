//成对出现的一组数据叫做对组，可以实现同时返回两个数据
//两种创建方式：
//pair<type, type> p(value1, value2);
//pair<type, type> p = make_pair(vlaue1, value2);
#include<string>
#include<iostream>
#include<set>
using namespace std;

void Printset(set<int>& s){
	for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	//第一种创建方式：
	pair<string, int>p1("Tom", 15);
	cout << "姓名：" << p1.first << " 年龄：" << p1.second << endl;

	//第二种创建方式：
	pair<string, int> p2 = make_pair("Jerry", 14);
	cout << "年龄；" << p2.first << " 年龄：" << p2.second << endl;
}


int main(){
	test1();

	return 0;
}
