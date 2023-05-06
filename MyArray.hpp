#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray{
public:
	//有参构造，参数 容量
	MyArray(int capacity) :m_Capacity(capacity){
		//cout << "MyArray的有参构造调用" << endl;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr){
		//cout << "MyArray的拷贝构造调用" << endl;

		this->m_Size = arr.m_Size;
		this->m_Capacity = arr.m_Capacity;
		//深拷贝 - 不能简单的将地址直接拷贝，这样会导致空间重复释放
		this->pAddress = new T[arr.m_Capacity];

		//将arr中原来的数据都拷贝到新的PAddress
		for (int i = 0; i < this->m_Size; ++i){
			this->pAddress[i] = arr.pAddress[i];
		}

	}

	//operator= - 防止深拷贝
	MyArray& operator=(const MyArray& arr){
		//if (*this == arr){
		//	//检测自我拷贝情况
		//  //如果不重载 == 号运算符，那么该部分代码只能运用于内置数据类型的判断
		//	return *this;
		//}

		//先判断原来的堆区当中是否有数据，如果有先释放
		if (this->pAddress != NULL){
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		//cout << "MyArray的operator=调用" << endl;

		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; ++i){
			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//尾插法
	void pushBack(const T& val){
		//判断容量是否已经等于大小
		if (this->m_Capacity == this->m_Size){
			cout << "添加失败，数组容量已满！" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		++this->m_Size;
	}

	//尾删法
	void PopBack(){
		//只要让用户访问不到最后一个元素 代表尾删 逻辑尾删
		if (this->m_Size == 0){
			return;
		}
		--this->m_Size;
	}

	//要想通过小标的方式来索引元素，需要重载[]运算符
	T& operator[](int index){
		return this->pAddress[index];
	}

	//返回数组的容量
	int GetCapacity(){
		return this->m_Capacity;
	}

	//返回数组大小
	int GetSize(){
		return this->m_Size;
	}


	//析构函数
	~MyArray(){
		if (this->pAddress != NULL)
		{
			//cout << "MyArray的析构函数调用" << endl;

			delete[] pAddress;
			pAddress = NULL;
		}
	}

private:
	T* pAddress;

	int m_Capacity;//数组容量

	int m_Size;//数组当前大小
};