//set������
//����Ԫ���ڲ���ʱ���ᱻ����
//���ʣ� 
//set/multiset���ڹ���ʽ�������ײ���õ��Ƕ�����ʵ��
//
//set��multiset������
//set���������������ظ���Ԫ�ش���
//multiset�������������ظ���Ԫ�ش���

//set�������ݵ�ͬʱ�᷵�ز���������ʾ����ɹ�
//multiset���������ݣ���˿��Բ����ظ�����
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
	//�ö������һ����������ݵ�ʱ���Ƿ��ɹ���
	pair<set<int>::iterator,bool> ret = s1.insert(30);

	//ret.second - ��ʶ����pair<set<int>::iterator,bool>���е�bool������Ƿ�������ݳɹ�
	if (ret.second){
		cout << "����ɹ�" << endl;
	}
	else{
		cout << "����ʧ��" << endl;
	}

	ret = s1.insert(30);
	if (ret.second){
		cout << "����ɹ�" << endl;
	}
	else{
		cout << "����ʧ��" << endl;
	}
	//insert�����᷵��һ���������࣬�����������������set�ĵ�������boolֵȷ����,���boolֵ���������ж��Ƿ�����ݳɹ���

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it){
		cout << *it << endl;
	}
		 
}


int main(){
	test1();

	return 0;
}
