#include<iostream>
using namespace std;

class Person{
	int m_A;//�Ǿ�̬��Ա������������Ķ�����
	static int m_B;//��̬��Ա��������������Ķ�����

	void func(){} //�Ǿ�̬��Ա��������������Ķ�����
	static void func2(){} //��̬��Ա��������������Ķ�����
};
int Person::m_B = 0;
int main(){
	//���һ�����ǿ��࣬��ôϵͳ���ǻ����һ���ֽڵĿռ������࣬�ñ������ֿն���ռ�ڴ��λ��
	//ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
	cout << "Person��Ĵ�СΪ�� " << sizeof(Person) << endl;

	return 0;
}