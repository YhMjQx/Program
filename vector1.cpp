#include<vector>
#include<iostream>
#include<algorithm>//�����㷨��ͷ�ļ�
using namespace std;
using std::vector;


typedef vector<int> INTVEC;//vector<int> - ����һ������
//void ShowVec1(const INTVEC& v){
//	unsigned int i = 0;
//	//��unsigned�޷��ŵ�ԭ������Ϊsize()�ķ���ֵ��Ӧ�ľ����޷�������
//	for (i = 0; i < v.size(); i++){
//		cout << v[i] << endl;
//	}
//	cout << endl;
//}
//
//void ShowVec2(INTVEC& v){
//	//���õ��������������������������Խ��������������ͳ���ָ�룩
//	INTVEC::iterator it; //iterator - �����vector�����һ��������
//	for (it = v.begin(); it != v.end(); ++it){
//		cout << *it << " ";
//	}
//	cout << endl;
//}

void ShowVec3(const INTVEC& v){
	//���õ��������������������������Խ��������������ͳ���ָ�룩
	INTVEC::const_iterator it; //const_iterator - �����vector�����һ������������
	for (it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
	//string = basic_string<char>
	INTVEC v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	//ShowVec1(v);
	//ShowVec2(v);
	ShowVec3(v);

	//v.erase(v.begin() + 2);
	//ShowVec3(v);
	v.erase(v.begin(), v.begin() + 2);//���漰�������������䶼������ҿ�����
	ShowVec3(v);

	v.erase(remove(v.begin(), v.end(), 3),v.end());
	ShowVec3(v);
	return 0;
}