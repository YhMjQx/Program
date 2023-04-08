#include<iostream>
#include<string>
using namespace std;
class StringUtil{
public:
	static void LTrim(string& s);//去除左空格
	static void RTrim(string& s);//去除右空格
	static void Trim(string& s);//去除空格
};
void StringUtil::LTrim(string& s){
	//先定义一个空字符
	string empty = " \t";
	s.erase(0, s.find_first_not_of(empty));//erase(从哪开始删除，删除到什么位置);
	//从第一个位置开始删除，直到第一个不是空字符的地方
}
void StringUtil::RTrim(string& s){
	string empty = " \t";
	s.erase(s.find_last_not_of(empty));//从最后一个不是空字符的地方的后一个位置开始删除
}
void StringUtil::Trim(string& s){
	LTrim(s);
	RTrim(s);
}
int main(){
	string s1 = "  YhMjQx  ";
	StringUtil::LTrim(s1);
	cout << "[" << s1 << "]" << endl;
	StringUtil::RTrim(s1);
	cout << "[" << s1 << "]" << endl;

	string s2 = "  HYHYHY  ";
	StringUtil::Trim(s2);
	cout << "[" << s2 << "]" << endl;
	return 0;
}