#include<iostream>
using namespace std;

//��������int������
void SwapInt(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//������������������
void SwapDouble(double& a, double& b){
	double temp = a;
	a = b;
	b = temp;
}

//C++���кܶ��������ͣ�ÿһ���඼���Ե�����һ����������
//�������ݽ���������Ҫ��һ������ģ����ʵ�֣������ŷ���
template<typename T>
//����һ��ģ�壬���߱������������������ŵ�T��Ҫ����T��һ��ͨ����������
//template - ��������ģ��
//typename - ���������ķ������������ͣ�������class����
//T - ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
void MySwap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

void test1(){
	int a = 10;
	int b = 20;
	//SwapInt(a, b);

	//����ģ����������ַ�ʽ
	//1.�Զ������Ƶ�
	//��ʱ�����Ƶ���һ�µ��������ͣ�Ҳ����˵������ȥ���������ݵ�����һ��Ҫһ��
	MySwap(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	//2.��ʽָ������
	//����ģ������ݵ��б���Ҫȷ����T���������ͣ��ſ���ʹ��
	MySwap<int>(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

int main(){
	test1();
	return 0;
}