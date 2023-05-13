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
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}
	else{
		cout << "L1为空" << endl;
	}
	if (!L2.empty()){
		cout << "L2不为空" << endl;
		cout << "L2的大小为： " << L2.size() << endl;
	}
	else{
		cout << "L2为空" << endl;
	}
}

void test1(){
	//创建一个list容器
	list<int>L1;

	//添加数据
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

//交换
void test2(){
	list<int>L1;

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	list<int>L2(10, 39);
	cout << "交换前：" << endl;
	PrintAndSize(L1, L2);

	//cout << "L1的max大小为： " << L1.max_size() << endl;

	cout << "交换后：" << endl;
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
	//重新指定大小
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