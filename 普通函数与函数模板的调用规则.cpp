#include<iostream>
using namespace std;
//���ù������£�
//1.�������ģ�����ͨ���������Ե��ã����ȵ�����ͨ����
//2.����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//3.����ģ��Ҳ���Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��

void myPrint(int a, int b){
	cout << "������ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b){
	cout << "���ú���ģ��" << endl;
}
template<typename T>
void myPrint(T a, T b,T c){
	cout << "�������غ���ģ��" << endl;
}



//void myFunc(int a, int b);/*{
//	cout << "������ͨ����" << endl;
//}*/
//
//template<typename T>
//void myFunc(T a, T b){
//	cout << "���ú���ģ��" << endl;
//}


void test1(){
	int a = 10;
	int b = 20;

	//myPrint(a, b);//������ͨ����

	myPrint<>(a, b);
	myPrint(a, b, 39);

	char c = 'c';
	char d = 'd';

	myPrint(c, d);//���������ͨ�����Ļ����ᷢ������ʽ����ת�����п������ݻᷢ���ı䣬������ֱ���Ƶ���TΪchar��
}

//void test2(){
//	int a = 10;
//	int b = 20;
//
//	myFunc(a, b);//�ᱨ����Ϊ��Ҫ������ͨ������������ͨ����ûʵ��
//}


int main(){

	test1();
	//test2();
	return 0;
}