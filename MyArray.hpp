#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray{
public:
	//�вι��죬���� ����
	MyArray(int capacity) :m_Capacity(capacity){
		//cout << "MyArray���вι������" << endl;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr){
		//cout << "MyArray�Ŀ����������" << endl;

		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		//��� - ���ܼ򵥵Ľ���ֱַ�ӿ����������ᵼ�¿ռ��ظ��ͷ�
		this->pAddress = new T[arr.m_Capacity];

		//��arr��ԭ�������ݶ��������µ�PAddress
		for (int i = 0; i < this->m_Size; ++i){
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//operator= - ��ֹ���
	MyArray& operator=(const MyArray& arr){
		//if (*this == arr){
		//	//������ҿ������
		//  //��������� == �����������ô�ò��ִ���ֻ�������������������͵��ж�
		//	return *this;
		//}

		//���ж�ԭ���Ķ��������Ƿ������ݣ���������ͷ�
		if (this->pAddress != NULL){
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//cout << "MyArray��operator=����" << endl;

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; ++i){
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//β�巨
	void pushBack(const T& val){
		//�ж������Ƿ��Ѿ����ڴ�С
		if (this->m_Capacity == this->m_Size){
			cout << "���ʧ�ܣ���������������" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		++this->m_Size;
	}

	//βɾ��
	void PopBack(){
		//ֻҪ���û����ʲ������һ��Ԫ�� ����βɾ �߼�βɾ
		if (this->m_Size == 0){
			return;
		}
		--this->m_Size;
	}

	//Ҫ��ͨ��С��ķ�ʽ������Ԫ�أ���Ҫ����[]�����
	T& operator[](int index){
		return this->pAddress[index];
	}

	//�������������
	int GetCapacity(){
		return this->m_Capacity;
	}

	//���������С
	int GetSize(){
		return this->m_Size;
	}


	//��������
	~MyArray(){
		if (this->pAddress != NULL)
		{
			//cout << "MyArray��������������" << endl;

			delete[] pAddress;
			pAddress = NULL;
		}
	}

private:
	T* pAddress;

	int m_Capacity;//��������

	int m_Size;//���鵱ǰ��С
};