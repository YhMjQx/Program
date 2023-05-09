#include<iostream>
#include<deque>
using namespace std;

//deque 没有容量，只有元素个数

//deque.empty();//判断容器是否为空
//deque.size();//返回容器中元素个数
//deque.resize(num);//重新指定容器的长度为num，如果比原来的长，则以默认值填充多余的位置
//					//如果比员额长度短，则超出的数据被删除
//deqeu.resize(num, elem);//重新指定容器的长度，如果容器变长，则以elem填充新的位置
//						//如果热容器变短，则超出的元素被删除

void Printdeque(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	Printdeque(d1);

	if (d1.empty()){
		cout << "d1为空！" << endl;
	}
	else{
		cout << "d1不为空！" << endl;
	}

	d1.resize(5);
	Printdeque(d1);

	d1.resize(15, 39);
	Printdeque(d1);

}

int main(){
	test1();

	return 0;
}