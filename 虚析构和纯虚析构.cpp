#include<iostream>
#include<string>
using namespace std;

//多态使用时，如果子类当中涉及到了在堆区上开辟空间的情况，那么父类指针在释放时是无法调用子类的析构函数的
//也就是说，这种情况下，单单释放父类指针无法做到对堆区开辟的内存完全释放，可能会造成内存泄漏
//解决方法：将父类的析构函数改为虚析构或者纯虚析构

////虚析构和纯虚析构的共性：
//1.可以解决父类指针释放子类对象的问题
//2.虚析构和纯虚析构都需要对函数进行实现，类内声明，类外实现，但其他普通的纯虚函数是不需要对函数进行实现的

//虚析构和纯虚析构的区别：
//如果是纯虚析构，该类属于抽象类，无法实例化对象

class Animal{
public:
	Animal(){
		cout << "Animal 的构造函数调用" << endl;
	}

	//利用虚析构可以解决父类指针释放子类对象时，释放不干净的问题
	//virtual ~Animal(){
	//	cout << "Animal 的虚析构函数调用" << endl;
	//}

	//利用纯虚析构也可以解决这个问题
	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal::~Animal(){
	cout << "Animal 的纯虚析构函数调用" << endl;
}

class Cat :public Animal{
public:
	Cat(string name) :m_Name(new string(name)){
		//我们需要在Cat类内将开辟的name释放干净
		cout << "Cat 构造函数调用" << endl;
	}

	~Cat(){
		if (m_Name != NULL){
			cout << "Cat 的析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak(){
		cout << *m_Name << "猫在说话" << endl;
	}

	string* m_Name;
};

void test1(){
	Animal* animal = new Cat("hjx");
	animal->speak();
	//父类指针在析构时，不会调用子类的析构函数，因此，如果子类又在堆区开辟空间的属性时，这个操作就可能会导致内存泄漏
	delete animal;
	animal = NULL;
}

int main(){
	test1();
	return 0;
}