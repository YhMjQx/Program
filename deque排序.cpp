#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>// - al go ri thm
using namespace std;
//支持随机访问的容器，都可以使用sort算法直接进行升序

//使用sort算法，将deque的区间传给sort

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
	//尾插
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(39);
	d1.push_front(3939);
	Printdeque1(d1);

	cout << "排序后的结果： " << endl;
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
	cout << "排序后：" << endl;

	sort(v1.begin(), v1.end());
	Printdeque2(v1);

}

int main(){
	test1();
	//test2();
	return 0;
}