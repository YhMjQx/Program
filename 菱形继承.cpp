#include<iostream>
using namespace std;

//������
class Animal{
public:
	int m_Age;

};
//������̳У�������μ̳е����� - �ؼ��� - virtual
//�ڼ̳�֮ǰ���Ϲؼ���virtual
//��ô��Animal������Ļ���ͽ��� �����
//��������̳�֮�����������������̳���ȥ�Ķ���
//�������൱����ʵ�����������ָ�루vbptr��,�����ָ����ָ��������vbtable���ģ�
//�������м����� �����ָ��������ָ�뵽��ʵĿ�����ݵĵ�ַƫ���������������ʵĿ����������С�����൱�����ҽ�����һ��
//Ȼ����õ�ʱ��ͻ�ͨ����������ָ�룬�Լ�ƫ�������ҵ�������Ҫ������

//����
class Sheep:virtual public Animal{

};

//����
class Tuo :virtual  public Animal{

};

//������
class SheepTuo :public Sheep, public Tuo{

};

void test1(){
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "st.Sheep::m_A = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_A = " << st.Tuo::m_Age << endl;
	//������̳�֮��st.Sheep::m_Age��st.Tuo::m_Ageʵ������һ��m_Age����һ�ζ�m_Age��ֵΪ18���ڶ��θ�ֵΪ28
	cout << "st.m_Age = " << st.m_Age << endl;
	//���������μ̳е�ʱ������������ӵ����ͬ������ʱ����Ҫ��������������

	//���ǣ��������������������У�ֻ��Ҫ��һ�����ݼ��ɣ����μ̳е������ݴ������ݣ���Դ�˷�

}

int main(){
	test1();
	return 0;
}