//set������
//����Ԫ���ڲ���ʱ���ᱻ����
//���ʣ� 
//set/multiset���ڹ���ʽ�������ײ���õ��Ƕ�����ʵ��
//
//set��multiset������
//set���������������ظ���Ԫ�ش���
//multiset�������������ظ���Ԫ�ش���
#include<iostream>
#include<set>
using namespace std;

void Printset(set<int>& s){
	for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	s1.insert(39);

	Printset(s1);

	//����
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end()){
		cout << "�ҵ�Ԫ�أ�" << *pos << endl;
	}
	else{
		cout << "û�ҵ�Ԫ��" << endl;
	}
}

void test2(){
	multiset<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	s1.insert(39);


	//ͳ��
	//����set������˵��count�Ľ����Զ����0 ��1����Ϊset�����洢�ǲ�������ظ���
	//��multiset�Ͳ�һ����
	cout << "s1��30�ĸ���Ϊ�� " << s1.count(30) << endl;
	cout << "s1��300�ĸ���Ϊ�� " << s1.count(300) << endl;


}

int main(){
	test1();
	test2();
	return 0;
}
