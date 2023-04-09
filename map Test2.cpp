#include<map>
#include<string>
#include<iostream>
using namespace std;

int main(){

	//插入到map容器当中的元素是默认按照key从小打到的顺序排序的，所以对key类型有要求，必须重载的有"<"运算符
	//如果key的数据重复了怎么办呢？那么就要看插入的方式了：
	//如果是用[]的方式来插入的话，key重复了，那么最后value对应的值就是最后插入的值，这种方式是允许会被改变的

	map<string, int> mapTest;
	//map<key类类型，value值类型（任意的类型）> - 模板类
	//mapTest - 模板类类对象

	mapTest["aaa"] = 100;		//int& operator[](const string& index);
	//插入一个key等于aaa的元素，他的初始值是int类型的空值，也就相当于0，然后把100复制给他


	mapTest.insert(map<string, int>::value_type("bbb", 200));
	//(map<string, int>::value_type - 这是一个类型
	//通过带有两个参数的构造函数，构造了 - 类类型接收两个参数来构造一个对象 第一个参数是key，第二个参数就是value
	//然后将构造好的对象插入map容器当中
	//修改
	mapTest["bbb"] = 2000;

	mapTest.insert(pair<string, int>("ccc", 300));
	//pair<string, int> - 这就是一个类型
	//pair<string, int>("ccc", 300) - 给这个类型传两个参数构造一个对象

	mapTest.insert(make_pair("ddd", 400));
	//make_pair -  是一个函数，返回了一个pair类类型的对象，但本质上还是构造了一个pair类类型的对象

	//查找+修改
	int n = mapTest["bbb"];
	//这样可以访问key = bbb对应的value值
	cout << n << endl;
	map<string, int>::iterator it;
	it = mapTest.find("ccc");//这种方式的优点在于可以判定it.find()是否查找到
	if (it != mapTest.end()){
		//在这里说明it找到了key=ccc的元素
		it->second = 3000;
		//cout << it->second << endl;
	}
	else{
		//此时说明it遍历到map容器的最后都没有找到key=ccc的元素
		cout << "not find" << endl;
	}


	//用迭代器来遍历map容器
	//map<string, int>::const_iterator it;//map<string, int>这个类的迭代器,const_iterator it,这里的it可以改变，不能改变的是it->指向的内容
	for (it = mapTest.begin(); it != mapTest.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}