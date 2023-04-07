#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string s1("YhMjQx");
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.empty() << endl;

	cout << s1.substr(0, 3) << endl;//char* substr(从何地开始取，取多少个) ，返回一个字符串,并且不改变源字符串
	cout << s1.substr(1) << endl;//s1.substr(1) - s1.substr(1,-1) - s1.substr(1,string::npos)

	
	//string::size_type pos = s1.find('M', 1);//find(查找哪个字符串，从哪开始查找)
	//if (pos == string::npos){
	//	cout << "not find" << endl;
	//}
	//else{
	//	cout << "pos=" << pos << endl;
	//}
	
	string::size_type rpos = s1.rfind('x');//find(查找哪个字符串，从哪开始查找)
	if (rpos == string::npos){
		cout << "not rfind" << endl;
	}
	else{
		cout << "rpos=" << rpos << endl;
	}
	return  0;
}