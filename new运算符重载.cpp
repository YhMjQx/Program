#include<iostream>
using namespace std;
class Test{
public:
	Test(int n) :n_(n){
		cout << "Test(int n)" << endl;
	}

	Test(const Test& other){
		cout << "Test(const Test& other)" << endl;
	}

	~Test(){
		cout << "~Test" << endl; 
	}



	//��ֲ���operator new����
	void* operator new(size_t size){
		cout << "void* operator new(size_t size)" << endl;
		void* p = malloc(size);
		return p;
	}
	void operator delete(void* p){
		cout << "void operator delete(void* p)" << endl;
		free(p);
	}
	void operator delete(void* p, size_t size){
		cout << "void operator delete(void* p)" << endl;
		free(p);
	}



	//��������Ǿֲ���placement new����
	void* operator new(size_t size, void* p){
		return p;
	}
	void operator delete(void*, void*){
	}



	//�ֲ����ļ�׷��operator new��������
	void* operator new(size_t size, const char* file, long line){
		cout << file << ":" << line << endl;
		void* p = malloc(size);
		return p;
	}
	void operator delete(void* p, const  char* file, long line){
		cout << file << ":" << line << endl;
		free(p);
	}
//private:
	int n_;
};



//���������ȫ�ֵ�operator new����
void* operator new(size_t size){
	cout << "Global void* operator new(size_t size)" << endl;
	void* p = malloc(size);
	return p;
}
void operator delete(void* p){
	cout << "Global void operator delete(void* p)" << endl;
	free(p);
}



//ȫ�ֵ�operator new�������������
void* operator new[](size_t size){
	cout << "void* operator new(size_t size)[]" << endl;
	void* p = malloc(size);
	return p;
}
void operator delete[](void* p){
	cout << "void operator delete(void* p)[]" << endl;
	free(p);
}



int main(){
	Test* p1 = new Test(39);
	delete p1;
		//�����new operator = operator new �ټ��� ���캯���ĵ���
		//placement new - ���Ѿ����ڵ��ڴ��Ϲ������,���ַ����ǲ������ڴ��
	char* str1 = new char;
	delete str1;
	
	char* str2 = new char[39];
	delete[] str2;

//�������ϵ��õ���operator new��operator delete���������

	char chunk[10];

	Test* p2 = new (chunk)Test(3939);//placement new �ټ��� ���캯��
	p2->~Test();
	//���ﲢ�����ڶ��Ͽ��ٵ��ڴ棬����chunk���ڴ棬���Բ���delete����������������
		//���������chunk��10���ֽ��Ͻ��в����ģ�3939���ĸ��ֽ����õ�chunk�Ŀռ�
		//ʵ���ϣ�p2���ָ���chunk���ָ������ȵ�
	cout << p2->n_ << endl;
	Test* p3 = reinterpret_cast<Test*>(chunk);
	cout << p3->n_ << endl;


#define new new(__FILE__,__LINE__)
	Test* p4 = new Test(1314);
	delete p4;

	return 0;
}