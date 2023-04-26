#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void test1(){
	//包含头文件

	//创建流对象
	ifstream ifs;

	//打开文件，并且判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}

	//读数据
	char buf[1024] = { 0 };

	while (ifs >> buf){
		//当数据全部读完，也就是文件读到尾了之后，就会自动结束
		cout << buf << endl;
	}
	//关闭文件
	ifs.close();
}

void test2(){

	//创建流对象
	ifstream ifs;

	//打开文件，并且判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}

	//读数据
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))){
		cout << buf << endl;
	}
	//关闭文件
	ifs.close();
}

void test3(){
	//创建流对象
	ifstream ifs;

	//打开文件，并且判断是否打开成功
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}

	//读数据
	string buf;
	while (getline(ifs, buf)){
		cout << buf << endl;
	}
	//关闭文件
	ifs.close();
}
int main(){

	//test1();
	//test2();
	test3();
	return 0;
}