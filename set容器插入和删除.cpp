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

	//ɾ��
	s1.erase(s1.begin());

	s1.erase(39);
	Printset(s1);

	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	Printset(s1);

}

int main(){
	test1();

	return 0;
}
