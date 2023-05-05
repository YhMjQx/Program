#include<iostream>
#include<string>
using namespace std;


template<class NameType, class AgeType= int>
class Person{
public:
	Person(NameType name, AgeType age ) :m_Name(name), m_Age(age){

	}

	void ShowInfo(){
		cout << "���֣�" << m_Name << " ���䣺" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//��ģ��û���Զ������Ƶ��ķ�ʽ
void test1(){
	//Person("������", 19); - error,��ģ�岻���Լ������Ƶ�������������޷���NameType�Ƶ�Ϊstring���޷���AgeType�Ƶ�Ϊint
	Person<string ,int> p("������", 19);
	p.ShowInfo();
}

//��ģ����ģ������б��п�����Ĭ�ϲ���
void test2(){
	Person<string> p("����ǿ",19);
	p.ShowInfo();
}

int main(){

	test1();

	test2();
	return 0;
}