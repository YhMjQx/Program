#include<iostream>
#include<vector>
using namespace std;

void Printvector(vector<int>& v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}
	Printvector(v1);

	//赋值 operator=
	vector<int>v2;
	v2 = v1;
	Printvector(v2);

	//assign
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	Printvector(v3);

	//n个elem的方式
	vector<int>v4;
	v4.assign(10, 39);
	Printvector(v4);

}

int main(){
	test1();
	return 0;
}