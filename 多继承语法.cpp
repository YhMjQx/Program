#include<iostream>
using namespace std;
//��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
//C++ʵ�ʿ����в������ö�̳�

class Base1{
public:
	Base1(/*int a*/){
		m_A = 100;
	}
	int m_A;
};

class Base2{
public:
	Base2(/*int b*/){
		m_A = 200;
	}
	int m_A;
};

//���� ��̳�Base1��Base2
class Son :public Base1, public Base2{
public:
	Son(int c,int d):m_C(c),m_D(d){

	}
	int m_C;
	int m_D;
};

void Test1(){
	Son s(300,400);
	cout << "sizeof(s) = " << sizeof(s) << endl;
	cout << "Base1::m_A = " << s.Base1::m_A << endl;
	cout << "Base2::m_A = " << s.Base2::m_A << endl;

}

int main(){
	Test1();
	return 0;
}