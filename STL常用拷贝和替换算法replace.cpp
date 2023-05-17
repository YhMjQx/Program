#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v;
	v.push_back(39);
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	v.push_back(39);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	replace(v.begin(), v.end(), 39, 393939);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

//class Greater10{
//public:
//	bool operator()(int val){
//		return val > 10;
//	}
//};

//ʹ���������ν�ʵ�ʱ����Ҫ����һ�������ĺ�������

bool Greater10(int val){
	return val > 10;
}
//�������ν�ʣ�ֻ��һ���������䵱�˺������������

void test2(){
	vector<int>v;
	v.push_back(39);
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	v.push_back(39);

	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;


	replace_if(v.begin(), v.end(), Greater10, 393939);
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

int main(){
	//test1();
	test2();

	return 0;
}