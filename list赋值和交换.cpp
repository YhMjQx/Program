#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>& L){
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void PrintAndSize(list<int>&L1,list<int>&L2){
	PrintList(L1);
	PrintList(L2);
	if (!L1.empty()){
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ�� " << L1.size() << endl;
	}
	else{
		cout << "L1Ϊ��" << endl;
	}
	if (!L2.empty()){
		cout << "L2��Ϊ��" << endl;
		cout << "L2�Ĵ�СΪ�� " << L2.size() << endl;
	}
	else{
		cout << "L2Ϊ��" << endl;
	}
}

void test1(){
	//����һ��list����
	list<int>L1;

	//�������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	PrintList(L1);

	list<int>L2;
	L2 = L1;
	PrintList(L2);

	list<int>L3;
	L3.assign(L1.begin(), L1.end());
	PrintList(L3);

	list<int>L4;
	L4.assign(10, 39);
	PrintList(L4);

}

//����
void test2(){
	list<int>L1;

	//�������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	list<int>L2(10, 39);
	cout << "����ǰ��" << endl;
	PrintAndSize(L1, L2);

	//cout << "L1��max��СΪ�� " << L1.max_size() << endl;

	cout << "������" << endl;
	L1.swap(L2);
	PrintAndSize(L1, L2);

}

void test3(){
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	//����ָ����С
	L1.resize(10, 39);

	PrintList(L1);
	L1.resize(3);
	PrintList(L1);

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}