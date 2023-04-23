#include<iostream>
using namespace std;

class Base{
public:
	static int m_A;

	static void func(){
		cout << "Base - static void func()" << endl;
	}

	static void func(int a){
		cout << "Base - static void func(int a)" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base{
public:
	static int m_A;

	static void func(){
		cout << "Son - static void func()" << endl;
	}


};
int Son::m_A = 200;

//ͬ���ľ�̬��Ա�����Ĵ�����
void test1(){
	Son s1;
	//1.ͨ���������
	cout << "ͨ��������ʣ�" << endl;
	cout << "Son �� m_A = "<< s1.m_A << endl;
	cout << "Base �� m_A = " << s1.Base::m_A << endl;

	cout << "ͨ���������ʣ�" << endl;
	cout << "Son �� m_A = " << Son::m_A <<endl;
	//��һ��::����ͨ�������ķ�ʽ����  �ڶ���::������ʸ����µ�������
	//ͨ��Son�����ʸ����������µ�m_A
	cout << "Base �� m_A = " << Son::Base::m_A << endl;
}


//ͬ����̬��Ա�����Ĵ�����
void test2(){
	Son s;
	//ͨ��������ʾ�̬��Ա����
	cout << "ͨ��������ʾ�̬��Ա����:" << endl;
	s.func();
	s.Base::func();
	//ͨ���������ʾ�̬��Ա����
	cout << "ͨ���������ʾ�̬��Ա����:" << endl;
	Son::func();
	Son::Base::func();

	//������ֺ͸���ͬ���ľ�̬��Ա������Ҳ�����ظ���������ͬ���ĳ�Ա����
	//�������ø����б����ص�ͬ����Ա��������Ҫ��������
	Son::Base::func(100);
}
int main(){
	test1();
	test2();
	return 0;
}