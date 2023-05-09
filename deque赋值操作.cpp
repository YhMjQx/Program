#include<iostream>
#include<deque>
using namespace std;

void Printdeque(deque<int>&d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	Printdeque(d1);

	//µÈºÅ¸³Öµ
	deque<int >d2;
	d2 = d1;
	Printdeque(d2);

	deque<int>d3;
	d3.assign(d2.begin(), d2.end());
	Printdeque(d3);

	deque<int>d4(10, 39);
	Printdeque(d4);


}


int main(){
	test1();

	return 0;
}