#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string s1;
	string s2("YhMjQx");
	cout << s2 << endl;

	basic_string<char>s3("HYHYHY");		//�ȼ���string s3("HYHYHY");
	cout << s3 << endl;

	string s4("YhMjQx", 3);		//YhM

	string s5("Y love H");		//HY
	string s6(s4, 2, 5);		//love��
	//cout << s4 << endl;
	cout << s6 << endl;

	string s7(3, 'H');
	cout << s7 << endl;

	//string::iterator first = s4.begin() + 2;
	//string::iterator last = s4.end();
	////string::iterator last = s4.begin()+ 5;
	//	//����������begin�Ļ��Ͳ���������һ����Ҳ����˵��ʱ��������[s4.begin() + 2,s4.begin()+ 5)
	//string s8 = (first, last);


	return 0;
}