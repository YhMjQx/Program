#include<iostream>
#include<string>
using namespace std;

//��ӡ�����
class MyPrint{
public:
	MyPrint(string name) :m_name(name){

	}

	//������������������Ǻ����ģ����Ǹ������ǵ����������صģ��ͱ���˵�������Ҫ����ַ��ܲң����ҵ�ʵ�־�������ַ���
	//���Ǳ��������ܾͲ�һ���ˣ���ô���Ǿ���Ҫ����ʵ������
	void operator()(string name){
		cout << name << endl;
	}

	string m_name;
};

void test1(){
	MyPrint myprint("YhMjQx");

	myprint.operator()(myprint.m_name);
}

int main(){
	test1();
	return 0;
}