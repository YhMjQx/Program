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

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	replace(v.begin(), v.end(), 39, 393939);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

//class Greater10{
//public:
//	bool operator()(int val){
//		return val > 10;
//	}
//};

//使用上面这个谓词的时候需要构造一个匿名的函数对象

bool Greater10(int val){
	return val > 10;
}
//这个不叫谓词，只是一个函数，充当了函数对象的作用

void test2(){
	vector<int>v;
	v.push_back(39);
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	v.push_back(39);

	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;


	replace_if(v.begin(), v.end(), Greater10, 393939);
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

int main(){
	//test1();
	test2();

	return 0;
}