#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string strinfo = "//*---Hello World!......------";
	string strset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		//strinfo.find_first_not_of(strset); - 找到strinfo在strset中第一个出现的不相等的字符
	string::size_type first = strinfo.find_first_of(strset);//找到strinfo在strset中第一个出现的相等字符
	if (first == string::npos){
		cout << "not find any characters" << endl;
	}

		//strinfo.find_last_not_of(strset); - 找到strinfo在strset中最后一个出现的不相等的字符
	string::size_type last = strinfo.find_last_of(strset);//找到strinfo在strset中最后一个出现的相等字符
	if (last == string::npos){
		cout << "not find any characters" << endl;
	}
	cout << strinfo.substr(first, last-first+1) << endl;// last-first+1 - 这个是取得字符串的字符个数

	return 0;
}