#include<iostream>
#include<string>
using namespace std;
class StringUtil{
public:
	static void LTrim(string& s);//ȥ����ո�
	static void RTrim(string& s);//ȥ���ҿո�
	static void Trim(string& s);//ȥ���ո�
};
void StringUtil::LTrim(string& s){
	//�ȶ���һ�����ַ�
	string empty = " \t";
	s.erase(0, s.find_first_not_of(empty));//erase(���Ŀ�ʼɾ����ɾ����ʲôλ��);
	//�ӵ�һ��λ�ÿ�ʼɾ����ֱ����һ�����ǿ��ַ��ĵط�
}
void StringUtil::RTrim(string& s){
	string empty = " \t";
	s.erase(s.find_last_not_of(empty));//�����һ�����ǿ��ַ��ĵط��ĺ�һ��λ�ÿ�ʼɾ��
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