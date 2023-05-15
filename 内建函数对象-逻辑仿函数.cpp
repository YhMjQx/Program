#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//template<class T> bool logical_and<T>	//逻辑与
//template<class T> bool logical_or<T>	//逻辑或
//template<class T> bool logical_not<T>	//逻辑非


void test1(){
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//将v1容器映射到v2容器当中，并采用逻辑非的方式映射
	//由于vector中的数据是用bool值创建的，所以logical_not<bool>当中也要用bool
	//重点重点重点！！！
	//在transform之前一定要给v2开辟好应有的空间,否则直接将数据拷进去，相当于覆盖了不属于自己的空间，叫非法访问
	vector<bool>v2;
	v2.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

}

int main(){
	test1();

	return 0;
}