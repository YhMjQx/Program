#include<iostream>
#include<vector>
using namespace std;

//vector的空间不够的时候不会去看后面空间够不够，而会直接选择一片足够的空间将原来的数据拷贝进去
//释放原有空间，然后返回这片新的空间

void Printvector(vector<int>&v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	vector<int> v1;
	for (int i = 0; i < 5; ++i){
		v1.push_back(i);
	}
	Printvector(v1);

	//通过区间的方式进行构造
	vector<int>v2(v1.begin(), v1.end());//这里的区间都是左闭右开
	Printvector(v2);

	//n个num的构造方式
	vector<int>v3(10, 39);
	Printvector(v3);

	//拷贝构造
	vector<int>v4(v3);
	Printvector(v4);


}

int main(){
	test1();
	return 0;
}