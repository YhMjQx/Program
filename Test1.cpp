#include<iostream>
using namespace std;


class ObjectB{
public:
	ObjectB(){
		cout << "ObjectB..." << endl;
	}
	ObjectB(int b) :objb_(b){

	}
	~ObjectB(){
		cout << "~ObjectB..." << endl;
	}
	int objb_;
};

class ObjectD{
public:
	ObjectD(){

	}
	ObjectD(int d): objd_(d){
		cout << "ObjectD..." << endl;
	}
	~ObjectD(){
		cout << "~ObjectD..." << endl;
	}
	int objd_;
};

class Base{
public:
	Base(){
		cout << "Base..." << endl;
	}
	Base(int b) :b_(b){
		cout << "Base..." << endl;
	}
	//�������캯����������ĳ�Ա�Ƕ��ڳ�ʼ���б��н��г�ʼ���ǽϺõ�
	Base(const Base& other) :objb_(other.objb_), b_(other.b_)
	{

	}
	~Base(){
		cout << "~Base..." << endl;
	}
	int b_;
	ObjectB objb_;
};

class Derived :public Base{
public:
	Derived(int b,int d) :d_(d), Base(b),objd_(222)
	{
		cout << "Derived..." << endl;
	}

	//�������캯������ͨ���캯���ĳ�ʼ���б�Ӧ���ǲ��ģ����������������������
	Derived(const Derived& other) :d_(other.d_), objd_(other.objd_), Base(other)
	{
		
	}
	~Derived(){
		cout << "~Derived..." << endl;
	}
	int d_;
	ObjectD objd_;
};

int main(){
	Derived d1(39,93);
	//������Σ������ȹ���Base��Ķ���Ȼ���ڹ������������
	cout << "Base - " << d1.b_ <<endl<< "Derived - " << d1.d_ << endl;

	Base b1(100);
	Base b2(b1);
	cout << b2.b_ << endl;


	//Derived d2(d1);
	return 0;
}
//������������ε��þ���Ķ����Ա���������û��Ĭ�Ϲ��캯������ô�ͱ���������Ĺ��캯���ĳ�ʼ���б��ж�����г�ʼ��