#include<iostream>
using namespace std;

//�������������
class Person{
public:
	friend ostream&  operator<<(ostream cout, Person& p);
	//���ó�Ա�������������������p.operator(cout)�򻯰汾p<<cout
	//�������ó�Ա��������<<���������Ϊ�����޷�ʵ��cout<<p����cout�����
	//void operator<<( cout ){
	//}

	//Person(int a, int b) :m_A(a), m_B(b){

	//}
//private:
	int m_A;
	int m_B;
};

//ֻ������ȫ�ֺ����������������
ostream&  operator<<(ostream cout, Person& p){ // ���ʣ�operator<<(cout,p),��cout<<p
	cout << "m_A= " << p.m_A <<" "<< "m_B= " << p.m_B;
	return cout;
}

void test1(){
	Person p;
	p.m_A = 10;
	p.m_B = 10;

	cout << p.m_A << endl; 
}

int main(){
	test1();
	return 0;
}