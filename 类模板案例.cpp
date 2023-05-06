#include<iostream>
#include<string>
#include"MyArray.hpp"
using namespace std;

//案例描述：
//1.可以对内置数据类型以及自定义数据类型的数据进行存储
//2.将数组中的数据存储到堆区
//3.构造函数中可以传入数组的容量
//4.提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//5.提供尾插法和尾删法对数组中的数据进行增加和删除
//6.可以通过下标的方式访问数组中的元素
//7.可以获取数组中当前元素个数和容量大小

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

	cout << "数组的容量为： " << arr1.GetCapacity() << endl;
	cout << "数组的大小为： " << arr1.GetSize() << endl;
}


//测试自定义数据类型
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
		cout << "姓名： " << arr[i].m_Name << " 年龄： " << arr[i].m_Age << endl;
	}
}

void test2(){
	MyArray<Person> arr(10);
	Person s1("胡佳欣", 19);
	Person s2("杨明强", 19);
	Person s3("胡杨", 0);

	//将数据插入到数组中
	arr.pushBack(s1);
	arr.pushBack(s2);
	arr.pushBack(s3);

	PrintMyArray(arr);

	cout << "数组容量为： " << arr.GetCapacity()<<endl;
	cout << "数组大小为： " << arr.GetSize() << endl;

}

int main(){

	test1();
	test2();
	return 0;
}