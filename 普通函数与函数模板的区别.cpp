//��ͨ�����뺯��ģ�������
//1.��ͨ�����ڵ���ʱ���Է����Զ�����ת������ʽ����ת����
//2.����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��(��Ϊ�Զ������Ƶ�ʱ��Ҫ������������һ��)
//3.���������ʽָ�����͵ķ�ʽ�����Է�����ʽ����ת��

#include<iostream>
using namespace std;

int Add(int a, int b){
	return a + b;
}

template<typename T>
T ADD(T a, T b){
	return a + b;
}


void test1(){
	int a = 10;
	int b = 20;

	char ch = 'c';
	cout << Add(a, b) << endl;
	cout << Add(a, ch) << endl;//a - 97 ;c - 99
	//�ַ�����ʽ����ת��Ϊ���ε�ʱ�򣬻�ʹ����ASCII��ֵ

	//�Զ������Ƶ�
	cout << ADD(a, b) << endl;
	//cout << ADD(a, ch) << endl; - error

	//��ʽָ������
	cout << ADD<int>(a, ch) << endl;
	//�������ֱ��ָ��a , chҪ�����εģ����Ի��Զ���chת��Ϊ����
}

int main(){
	test1();
	return 0;
}