//�ɶԳ��ֵ�һ�����ݽ������飬����ʵ��ͬʱ������������
//���ִ�����ʽ��
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
	//��һ�ִ�����ʽ��
	pair<string, int>p1("Tom", 15);
	cout << "������" << p1.first << " ���䣺" << p1.second << endl;

	//�ڶ��ִ�����ʽ��
	pair<string, int> p2 = make_pair("Jerry", 14);
	cout << "���䣻" << p2.first << " ���䣺" << p2.second << endl;
}


int main(){
	test1();

	return 0;
}
