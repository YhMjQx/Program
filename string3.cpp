#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string s1("YhMjQx");
	s1.replace(0, 2, "HYHYHY");//replace(从哪开始替换，替换掉几个字符，替换的内容是什么)；
	cout << s1 << endl;

	s1.insert(5, "1314");//insert(从哪开始插入，插入的内容是什么)；
	cout << s1 << endl;

	string s2("HYHYHY");
	s2.append("1314");
	cout << s2 << endl;

	string s3("H love Y");
	s3.swap(s2);
	cout << s2 << endl;
	cout << s3 << endl;

	s2.c_str();//将s2转换成const char* 的类型
	return  0;
}