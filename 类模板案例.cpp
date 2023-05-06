#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;

//����������
//1.���Զ��������������Լ��Զ����������͵����ݽ��д洢
//2.�������е����ݴ洢������
//3.���캯���п��Դ������������
//4.�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
//5.�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
//6.����ͨ���±�ķ�ʽ���������е�Ԫ��
//7.���Ի�ȡ�����е�ǰԪ�ظ�����������С

void PrintIntArr(MyArray<int>& arr){
	for (int i = 0; i < arr.GetSize(); ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1(){
	MyArray<int> arr1(5);
	
	for (int i = 0; i < 5; ++i){
		arr1.pushBack(i);
	}
	PrintIntArr(arr1);
	arr1.PopBack();
	PrintIntArr(arr1);

	cout << "���������Ϊ�� " << arr1.GetCapacity() << endl;
	cout << "����Ĵ�СΪ�� " << arr1.GetSize() << endl;
}


//�����Զ�����������
class Person{
public:
	Person(){}
	Person(string name, int age) :m_Name(name), m_Age(age){

	}
	string m_Name;
	int m_Age;
};

void PrintMyArray(MyArray<Person>& arr){
	for (int i = 0; i < arr.GetSize(); ++i){
		cout << "������ " << arr[i].m_Name << " ���䣺 " << arr[i].m_Age << endl;
	}
}

void test2(){
	MyArray<Person> arr(10);
	Person s1("������", 19);
	Person s2("����ǿ", 19);
	Person s3("����", 0);

	//�����ݲ��뵽������
	arr.pushBack(s1);
	arr.pushBack(s2);
	arr.pushBack(s3);

	PrintMyArray(arr);

	cout << "��������Ϊ�� " << arr.GetCapacity()<<endl;
	cout << "�����СΪ�� " << arr.GetSize() << endl;

}

int main(){

	test1();
	test2();
	return 0;
}