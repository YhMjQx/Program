#include<iostream>
#include<list>
using namespace std;

//list�����ĵ�������֧��������ʣ�ֻ��ǰ�ƺͺ��ƣ�list���������Ŀռ䣬���Բ�����at����[]����Ԫ��
//

void test1(){
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);

	cout << "l1�ĵ�һ������Ϊ�� " << l1.front() << endl;
	cout << "l1�����һ������Ϊ�� " << l1.back() << endl;

	list<int>::iterator it = l1.begin();
	it++;
	it--;
	//list�ĵ�����֧��ǰ�ƺͺ��ƣ����ǲ�֧����Ծʽ����
	//it = it + 2; - error


}

int main(){
	test1();

	return 0;
}