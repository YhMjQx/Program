#include<iostream>
using namespace std;

//�������������
class Person{
public:
	friend ostream&  operator<<(ostream& cout, Person& p);
	//���ó�Ա�������������������p.operator(cout)�򻯰汾p<<cout
	//�������ó�Ա��������<<���������Ϊ�����޷�ʵ��cout<<p����cout�����
	//void operator<<( cout ){
	//}

	Person(int a, int b) :m_A(a), m_B(b){

	}

	int GetPriA();

	int GetPriB();

private:
	int m_A;
	int m_B;
};

//ֻ������ȫ�ֺ����������������
ostream&  operator<<(ostream& cout, Person& p){ // ���ʣ�operator<<(cout,p),��cout<<p
	//ostream& cout - ����ҲҪ�����õ�ԭ������Ϊostream��Ӧ��coutֻ�����ҽ���һ��������������
	//��Ҳ��Ϊʲô������������õĻ���cout<< p <<endl;�е�cout�ͻᱨ����Ϊ������һ���µ�cout�����ǲ������
	cout << "m_A= " << p.m_A <<" "<< "m_B= " << p.m_B;
	return cout;//�÷���cout,Ҳ�����ٷ���һ��Ŷstream&��Ϊ��ȷ����ʽ��̣��ͱ��磬cout<<p.m_A<<endl;
				//���������һ���������ô���޷�ʵ����ʽ��̣�ֻ��cout<<p.m_A;
}

int Person::GetPriA(){
	return m_A;
}

int Person::GetPriB(){
	return m_B;
}

void test1(){
	Person p(10,10);

	cout << p << endl << "YhMjQx" << endl;//���д�������Ҳ��֪����ô����

	//cout << "m_A= " << p.GetPriA() << endl;
	//cout << "m_A= " << p.GetPriA() << endl;

}

int main(){
	test1();
	return 0;
}