#include<iostream>
using namespace std;

class Base{
public:
	Base(){
		cout << "Base���캯��" << endl;
	}

	~Base(){
		cout << "Base����������" << endl;
	}
};

class Son : public Base{
public:
	Son(){
		cout << "Son���캯��" << endl;
	}

	~Son(){
		cout << "Son����������" << endl;
	}
};

void Test1(){
	//Base b;
	Son s;
}

int main(){
	Test1();
	//���и�����е����࣬����һ������Ϊ��һ����ĳ�Ա�е���
	return 0;
}