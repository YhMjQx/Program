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



	//类局部的operator new重载
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



	//下面这个是局部的placement new重载
	void* operator new(size_t size, void* p){
		return p;
	}
	void operator delete(void*, void*){
	}



	//局部的文件追踪operator new函数重载
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



//这下面的是全局的operator new重载
void* operator new(size_t size){
	cout << "Global void* operator new(size_t size)" << endl;
	void* p = malloc(size);
	return p;
}
void operator delete(void* p){
	cout << "Global void operator delete(void* p)" << endl;
	free(p);
}



//全局的operator new关于数组的重载
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
		//这里的new operator = operator new 再加上 构造函数的调用
		//placement new - 在已经存在的内存上构造对象,这种方法是不分配内存的
	char* str1 = new char;
	delete str1;
	
	char* str2 = new char[39];
	delete[] str2;

//这里以上调用的是operator new和operator delete运算符重载

	char chunk[10];

	Test* p2 = new (chunk)Test(3939);//placement new 再加上 构造函数
	p2->~Test();
	//这里并不是在堆上开辟的内存，他是chunk的内存，所以不用delete，而是用析构函数
		//这里就是在chunk这10个字节上进行操作的，3939这四个字节是用的chunk的空间
		//实际上，p2这个指针和chunk这个指针是相等的
	cout << p2->n_ << endl;
	Test* p3 = reinterpret_cast<Test*>(chunk);
	cout << p3->n_ << endl;


#define new new(__FILE__,__LINE__)
	Test* p4 = new Test(1314);
	delete p4;

	return 0;
}