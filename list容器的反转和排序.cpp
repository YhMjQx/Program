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
	//���� - ǰһ���� > �ڶ�����
	return l1 > l2;
}

//��ת
void test1(){
	list<int>l1;
	l1.push_back(20);
	l1.push_back(50);
	l1.push_back(30);
	l1.push_back(10);
	l1.push_back(40);

	cout << "��תǰ�� " << endl;
	Printlist(l1);

	cout << "��ת�� " << endl;
	l1.reverse();
	Printlist(l1);

}

//����
void test2(){
	list<int>l1;
	l1.push_back(20);
	l1.push_back(50);
	l1.push_back(30);
	l1.push_back(10);
	l1.push_back(40);

	cout << "����ǰ�� " << endl;
	Printlist(l1);

	//���в�֧��������ʵ������������ǲ���ʹ�ñ�׼�㷨�ģ�
	//��ˣ���Щ��֧��������ʵ������������ڲ������Լ�ר���Ĺ����㷨

	l1.sort();//Ĭ��������
	cout << "�����: " << endl;
	Printlist(l1);

	//���������������ô���أ��ҿ��Ը�sort��һ���Ƚϵĺ�������������qsortһ����Ҫ����ȥһ���ȽϺ���
	l1.sort(Compare);
	cout << "����� " << endl;
	Printlist(l1);
}



int main(){
	//test1();
	test2();
	return 0;
}