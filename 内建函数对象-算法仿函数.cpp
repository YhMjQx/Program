//�ڽ���������
//���
//STL�ڽ���һЩ��������
//���ࣺ
//�㷨�º���
//��ϵ�º���
//�߼��º���
//�÷���
//��Щ�º����������Ķ����÷���һ��ĺ�����ͬ
//ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>

#include<iostream>
#include<functional>
using namespace std;

//template<class T> T negate<T> һԪ�º��� ȡ���º���
//template<class T> T plus<T> ��Ԫ�º��� �ӷ�
//template<class T> T minus<T> ��Ԫ�º��� ����
//template<class T> T multiplies<T> ��Ԫ�º��� �˷��º���
//template<class T> T divides<T> ��Ԫ�º���  �����º���
//template<class T> T modulus<T> ��Ԫ�º��� ȡģ�º���

void test1(){
	//˵����Щ���Ǻ���ģ��
	negate<int>n;
	//ȡ������

	cout << n(50) << endl;

}

void test2(){
	plus<int>p;
	cout << p(10, 20) << endl;

}

int main(){
	//test1();
	test2();
	return 0;
}