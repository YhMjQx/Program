#include<iostream>
using namespace std;

class Base{
public:
	Base() :x_(0){
	}

	int GetBaseX() const{
		return x_;
	}

	void Show(){
		cout << "Base::Show..." << endl;
	}

	int x_;
};

//�����࣬�����x_�ͻ����x_��һ��
//�������x_������x_�ض����ʱ����������������������ݳ�Ա����ô����ʵ�����������ݳ�Ա
class Derived : public Base{
public:
	Derived() :x_(0){

	}

	int GetDerivedX() const{
		return x_;
	}

	void Show(int n){
		cout << "Derived::Show..." << endl;
	}

	void Show(){
		cout << "Derived::Show..." << endl;

	}
	int x_;
};

int main(){

	Derived d;
	d.x_ = 39;
	d.Base::x_ = 93;//��Ҫ���ʻ��൱�е����ݳ�Ա�͵���ôд
	cout << d.GetBaseX() << endl;
	cout << d.GetDerivedX() << endl;

	d.Show();
	d.Show(0);
	d.Base::Show();//��Ҫ���ʻ����еĳ�Ա������Ҫ��ôд
	return 0;
}