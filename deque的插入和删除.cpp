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
	//β��
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	Printdeque(d1);
	
	//ͷ��
	d1.push_front(39);
	d1.push_front(39);
	Printdeque(d1);

	//βɾ
	d1.pop_back();
	d1.pop_back();
	Printdeque(d1);

	//ͷɾ
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

	//����
	d2.insert(d2.begin(), 39);//��d2.begin()���λ�ò�������39
	d2.insert(d2.end(), 2, 39);//��de.end()��λ�ò���2������39
	Printdeque(d2);


	deque<int>d3;
	d3.push_back(39);
	d3.push_front(39);
	d3.insert(d3.begin() + 1, d2.begin(), d2.end());
	//��d3.begin() + 1λ�ã���������[d2.begin(), d2.end())Ϊ������������
	Printdeque(d3);

}

void test3(){
	deque<int>d2;
	d2.push_back(10);
	d2.push_back(10);
	d2.push_front(20);
	d2.push_front(20);
	Printdeque(d2);

	//ɾ��
	d2.erase(d2.begin());
	Printdeque(d2);

	deque<int>::iterator it = d2.begin();
	++it;
	d2.erase(it);
	Printdeque(d2);

	//�����䷽ʽɾ��
	//d2.erase(d2.begin(), d2.end());
	//�������
	d2.clear();
	Printdeque(d2);

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}