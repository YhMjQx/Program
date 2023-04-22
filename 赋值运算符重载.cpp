#include<iostream>
using namespace std;
//��������г�Աָ�����������ֵ����ʱӦ���õ����

class Person{
public:
	Person(int age) :m_Age(new int(age)){

	}

	~Person(){
		if (m_Age != NULL){
			delete m_Age;
		}
	}

	//���ظ�ֵ�����
	Person& operator=(Person& p){
		//ע�⣬����Ӧ���ȿ����൱��ԭ���Ƿ�洢�������ݣ�����еĻ�������Ӧ�����ͷŸɾ���Ȼ���ڽ������
		if (m_Age != NULL){
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;//Ӧ�÷�������,Ŀ��Ϊ����ʵ����ʽ��̵Ĳ���
	}

//private:
	int* m_Age;
};

void test1(){
	Person p1(39);
	Person p2(18);
	Person p3(25);

	p3 = p2 = p1;

	cout << "p1������Ϊ��" << *p1.m_Age << endl;
	cout << "p2������Ϊ��" << *p2.m_Age << endl;
	cout << "p3������Ϊ��" << *p3.m_Age << endl;

	//���ֻ�Ǽ򵥵ĵ���ϵͳ�ṩ��Ĭ�ϸ�ֵ�������ǳ����������ô�Ὣm_Age���ָ���ֵ����ȫȫ��������һ�������ָ��
	//�������������ٵ�������������ʱ�򣬾ͻ��ͬһ��ռ���������ظ����ͷţ������ͻᵼ�����б���
	//��ʱ��Ҫ�Լ����صȺ������������Ϊ���
}

int main(){

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//a = b = c;
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	//��ô������ʵ�ֵĸ�ֵ���������ҲӦ�þ��������Ĺ���

	test1();
	return 0;
}