#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v1;
	v1.push_back(39);
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}
	v1.push_back(39);
	
	vector<int>v2;
	for (int i = 0; i < 5; ++i){
		v2.push_back(i);
	}
	cout << "����ǰ��" << endl;
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	for_each(v1.begin(), v1.end(), Print);
	cout << endl;
	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;
	for_each(v2.begin(), v2.end(), Print);
	cout << endl;

	cout << "----------------------" << endl;
	swap(v1, v2);
	cout << "������" << endl;
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	for_each(v1.begin(), v1.end(), Print);
	cout << endl;
	cout << "v2������Ϊ��" << v2.capacity() << endl;
	cout << "v2�Ĵ�СΪ��" << v2.size() << endl;
	for_each(v2.begin(), v2.end(), Print);
	cout << endl;


}


int main(){
	test1();


	return 0;
}