#include<iostream>
using namespace std;

class AbstractDrinking{
public:
	//��ˮ
	virtual void Boil() = 0;

	//����
	virtual void Brew() = 0;

	//���뱭��
	virtual void PourInCup() = 0;

	//��������
	virtual void PutSomething() = 0;

	//������Ʒ
	void makeDrink(){
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//��������
class makeCoffe:public AbstractDrinking{
public:
	//��ˮ
	virtual void Boil(){
		cout << "�����ˮ" << endl;
	}

	//����
	virtual void Brew() {
		cout << "����èʺ����" << endl;
	}

	//���뱭��
	virtual void PourInCup(){
		cout << "���뿧�ȱ�" << endl;
	}

	//��������
	virtual void PutSomething(){
		cout << "�����Ǻ�ţ��" << endl;
	}
};

//��������轲�
class makeTee:public AbstractDrinking{
public:
	//��ˮ
	virtual void Boil(){
		cout << "�����ˮ" << endl;
	}

	//����
	virtual void Brew() {
		cout << "���ݶ����˺�" << endl;
	}

	//���뱭��
	virtual void PourInCup(){
		cout << "����豭" << endl;
	}

	//��������
	virtual void PutSomething(){
		cout << "��������Ƭ�����" << endl;
	}
};

void dowork(AbstractDrinking* abd){
	abd->makeDrink();
	delete abd;//ע�⣬�����Ͽ��ٵĿռ�һ��Ҫ�ǵ��ͷ�
}

//�����Ȳ���
void test1(){
	dowork(new makeCoffe);
}

//��������轲����
void test2(){
	dowork(new makeTee);

}
int main(){
	test1();
	cout << "-------------" << endl;
	test2();
	return 0;
}