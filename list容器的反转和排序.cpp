#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void Printlist(list<int>&l){
	for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

bool Compare(int l1, int l2){
	//降序 - 前一个数 > 第二个数
	return l1 > l2;
}

//翻转
void test1(){
	list<int>l1;
	l1.push_back(20);
	l1.push_back(50);
	l1.push_back(30);
	l1.push_back(10);
	l1.push_back(40);

	cout << "翻转前： " << endl;
	Printlist(l1);

	cout << "翻转后： " << endl;
	l1.reverse();
	Printlist(l1);

}

//排序
void test2(){
	list<int>l1;
	l1.push_back(20);
	l1.push_back(50);
	l1.push_back(30);
	l1.push_back(10);
	l1.push_back(40);

	cout << "排序前： " << endl;
	Printlist(l1);

	//所有不支持随机访问迭代器的容器是不能使用标准算法的，
	//因此，这些不支持随机访问迭代器的容器内部配有自己专属的功能算法

	l1.sort();//默认是升序
	cout << "升序后: " << endl;
	Printlist(l1);

	//但是如果我像降序怎么办呢，我可以给sort传一个比较的函数，就类似于qsort一样需要传进去一个比较函数
	l1.sort(Compare);
	cout << "降序后： " << endl;
	Printlist(l1);
}



int main(){
	//test1();
	test2();
	return 0;
}