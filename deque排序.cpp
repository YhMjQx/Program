#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>// - al go ri thm
using namespace std;
//֧��������ʵ�������������ʹ��sort�㷨ֱ�ӽ�������

//ʹ��sort�㷨����deque�����䴫��sort

void Printdeque1(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void Printdeque2(vector<int>& d){
	for (vector<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	//β��
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(39);
	d1.push_front(3939);
	Printdeque1(d1);

	cout << "�����Ľ���� " << endl;
	sort(d1.begin(), d1.end());
	Printdeque1(d1);

}

void test2(){
	vector<int>v1;
	v1.push_back(99);
	v1.push_back(77);
	v1.push_back(55);
	v1.push_back(22);
	v1.push_back(66);
	v1.push_back(88);
	Printdeque2(v1);
	cout << "�����" << endl;

	sort(v1.begin(), v1.end());
	Printdeque2(v1);

}

int main(){
	test1();
	//test2();
	return 0;
}