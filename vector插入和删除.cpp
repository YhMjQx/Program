#include<iostream>
#include<vector>
using namespace std;

//push_back(ele);//尾部插入数据ele
//pop_back(ele);//尾部删除数据ele
//insert(const_iterator pos, ele);//在迭代器指向的位置pos处插入数据ele
//insert(const_iterator pos,int count, ele);//在迭代器指向的位置pos处插入count个数据ele
//erase(const_iterator pos);//删除迭代器pos指向位置的数据
//erase(const_iterator start,const_iterator end);//删除迭代器从start到end之间的元素
//clear();//删除容器中所有元素



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

	//尾删
	v1.pop_back();
	Printvector(v1);

	//插入
	v1.insert(v1.begin(), 39);//第一个参数是迭代器，可以是任意位置
	Printvector(v1);

	v1.insert(v1.begin(), 2, 39); //第一个参数是迭代器，可以是任意位置
	Printvector(v1);

	//删除
	v1.erase(v1.begin());//参数是迭代器，可以是任意位置
	Printvector(v1);

	//清空
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	Printvector(v1);

}

int main(){
	test1();
	return 0;
}