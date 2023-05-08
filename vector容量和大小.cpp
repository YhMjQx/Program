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

	if (v1.empty()){
		cout << "v1为空" << endl;
	}
	else{
		cout << "v1不为空" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小为：" << v1.size() << endl;
	}


	//重新指定大小
	v1.resize(15,39);//如果重新制定的大小过长，那么会默认用0来填充多余的空间
						//当然，也可以用指定的值来填充多余的空间
	Printvector(v1);

	v1.resize(10);//如果重新制定的大小比原来小，则超出的部分会被删掉
	Printvector(v1);

}

int main(){
	test1();
	return 0;
}