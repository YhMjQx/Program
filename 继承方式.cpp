#include<iostream>
using namespace std;

class Base{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};


class Son1 :public Base{
	void func(){
		m_A = 10;//�����й���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����б���Ȩ�޳�Ա�����������Ǳ���Ȩ��
		//m_C = 10;//�����е�˽��Ȩ�޳�Ա��������ʲ���
	}
};

void test1(){
	Son1 s1;
	s1.m_A = 10;
	//s1.m_B = 10;��Son1�У�m_B�Ǳ���Ȩ�ޣ�Son1������ʲ���
}

class Son2 :protected Base{
public:
	void func(){
		m_A = 100;//�����й�����Ա�������б�̱���Ȩ��
		m_B = 100;//�����б���Ȩ�޵������л��Ǳ���Ȩ��
		//m_C = 100;//�����е�˽��Ȩ�� ������ʲ���
	}

};

void test2(){
	Son2 s2;
	//s2.m_A = 1000;//��Son2��m_A�Ǳ���Ȩ�ޣ�������ʲ���
	//s2.m_B = 1000;//��Son2��m_B�Ǳ���Ȩ�ޣ�������ʲ���
}

class Son3 :private Base{
public:
	void func(){
		m_A = 100;//�����й��г�Ա�������б�Ϊ˽�г�Ա
		m_B = 100;//�����б�����Ա�������б�Ϊ˽�г�Ա
		//m_C = 100; - �����е�˽�г�Ա ������ʲ���
	}


};

void test3(){
	Son3 s3;
	//s3.m_A = 1000;//m_A�������б����˽�еĳ�Ա��������ʲ���
	//s3.m_B = 1000;//m_B�������б����˽�еĳ�Ա��������ʲ���
	//s3.m_C = 1000;//m_C�������б����˽�еĳ�Ա��������ʲ���
}

class GrandSon3:public Son3{
public:
	void func(){
		//m_A = 1000;
		//m_B = 1000;
		//�ɴ�Ҳ��֪,zai Son3������������Ա����˽�е�
	}
};

int main(){

	return 0;
}