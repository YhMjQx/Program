#include<iostream>
using namespace std;

class Base{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
	//
};

//���ÿ�����Ա������ʾ���鿴����ģ��
//��ת�̷�����ǰ���ǿ���ʾ���θ����ļ�����Ӧ���̷��Ƿ���һ�����̣�����ǾͲ���Ҫ�˲����ˣ�������Ǿͣ��̷�:
//��ת�ļ�·�� cd ����·����
//�鿴����
//c1 /d1 reportSingleClassLayout���� �ļ���

class Son :public Base{
public:
	int m_D;
	//�ڸ��������ԷǾ�̬��Ա���ᱻ����̳�����
	//������˽�еĳ�Ա���Ա������������ˣ����Է��ʲ�����������ʵ�ϵ�ȷ�Ǽ̳���ȥ��

};

void test1(){
	cout << "sizeof(Son)=  " << sizeof(Son) << endl; //  -  16
}

int main(){
	test1();
	return 0;
}