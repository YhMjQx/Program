#include<iostream>
#include<deque>
using namespace std;

void Printdeque(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	//尾插
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	Printdeque(d1);
	
	//头插
	d1.push_front(39);
	d1.push_front(39);
	Printdeque(d1);

	//尾删
	d1.pop_back();
	d1.pop_back();
	Printdeque(d1);

	//头删
	d1.pop_front();
	d1.pop_front();
	Printdeque(d1);

}


void test2(){
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(10);
	d2.push_front(20);
	d2.push_front(20);
	Printdeque(d2);

	//插入
	d2.insert(d2.begin(), 39);//在d2.begin()这个位置插入数据39
	d2.insert(d2.end(), 2, 39);//在de.end()的位置插入2个数据39
	Printdeque(d2);


	deque<int>d3;
	d3.push_back(39);
	d3.push_front(39);
	d3.insert(d3.begin() + 1, d2.begin(), d2.end());
	//在d3.begin() + 1位置，插入区间[d2.begin(), d2.end())为这个里面的数据
	Printdeque(d3);

}

void test3(){
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(10);
	d2.push_front(20);
	d2.push_front(20);
	Printdeque(d2);

	//删除
	d2.erase(d2.begin());
	Printdeque(d2);

	deque<int>::iterator it = d2.begin();
	++it;
	d2.erase(it);
	Printdeque(d2);

	//按区间方式删除
	//d2.erase(d2.begin(), d2.end());
	//类似清空
	d2.clear();
	Printdeque(d2);

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}