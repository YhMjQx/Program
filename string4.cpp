#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string strinfo = "//*---Hello World!......------";
	string strset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		//strinfo.find_first_not_of(strset); - �ҵ�strinfo��strset�е�һ�����ֵĲ���ȵ��ַ�
	string::size_type first = strinfo.find_first_of(strset);//�ҵ�strinfo��strset�е�һ�����ֵ�����ַ�
	if (first == string::npos){
		cout << "not find any characters" << endl;
	}

		//strinfo.find_last_not_of(strset); - �ҵ�strinfo��strset�����һ�����ֵĲ���ȵ��ַ�
	string::size_type last = strinfo.find_last_of(strset);//�ҵ�strinfo��strset�����һ�����ֵ�����ַ�
	if (last == string::npos){
		cout << "not find any characters" << endl;
	}
	cout << strinfo.substr(first, last-first+1) << endl;// last-first+1 - �����ȡ���ַ������ַ�����

	return 0;
}