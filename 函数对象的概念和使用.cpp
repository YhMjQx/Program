//��������ĸ��
//���غ������ò��������࣬����󳣳�Ϊ��������
//��������ʹ�����ص�()����Ϊ���ƺ������ã�Ҳ�зº���
//���ʣ�
//�����������һ���࣬���Ǻ���
//
//���������ʹ�ã�
//�ص㣺
//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
//3.�������������Ϊ��������
#include<iostream>
#include<string>
using namespace std;

class MyAdd{
public:
	int operator()(int a,int b){
		return a + b;
	}
};

class MyPrint{
public:
	MyPrint(){
		this->count = 0;
	}

	void operator()(string str){
		cout << str << endl;
		++this->count;
	}

	int count;

};


void test1(){
	MyAdd myadd;

	//1.����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
	cout << myadd(10, 20) << endl;
}

void test2(){
	//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
	MyPrint mp;
	mp("YhMjQx");
	mp("YhMjQx");
	mp("YhMjQx");
	mp("YhMjQx");

	cout << "myprint���ô���Ϊ��" << mp.count << endl;
}



void doPrint(MyPrint& mp,string str){
	mp(str);
}

void test3(){
	//3.�������������Ϊ�������� - ��һ���������������������ʱ��ı������������
	//�����������Զ����������͵�ʱ����Ҫ������ʱ��Ҫ�Լ�дһ���º�������Ϊ����Զ�����������ר�����������
	MyPrint mp;
	doPrint(mp,"YhMjQx");

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}