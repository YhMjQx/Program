#include<iostream>
#include<string>
using namespace std;
using std::string;

int main(){
	string s1("YhMjQx");
	s1.replace(0, 2, "HYHYHY");//replace(���Ŀ�ʼ�滻���滻�������ַ����滻��������ʲô)��
	cout << s1 << endl;

	s1.insert(5, "1314");//insert(���Ŀ�ʼ���룬�����������ʲô)��
	cout << s1 << endl;

	string s2("HYHYHY");
	s2.append("1314");
	cout << s2 << endl;

	string s3("H love Y");
	s3.swap(s2);
	cout << s2 << endl;
	cout << s3 << endl;

	s2.c_str();//��s2ת����const char* ������
	return  0;
}