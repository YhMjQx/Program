//template<class T> bool equal_to<T>;		//����
//template<class T> not_equal_to<T>;		//������
//template<class T> greater<T>;				//����
//template<class T> greater_equal<T>;		//���ڵ���
//template<class T> less<T>;				//С��
//template<class T> less_equal<T>;			//С�ڵ���
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


template<class T>
class Greater{
public:
	bool operator()(T val1,T val2){
		return val1 > val2;
	}
};

void test1(){
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "����ǰ��" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	cout << "�����" << endl;
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	cout << "�����" << endl;
	Greater<int> greater;
	sort(v.begin(),v.end(),greater);
	//sort(v.begin(), v.end(), Greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;



	vector<double>v2;
	v2.push_back(13.14);
	v2.push_back(1.14);
	v2.push_back(3.14);

	cout << "����ǰ��" << endl;
	for (vector<double>::iterator it = v2.begin(); it != v2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	cout << "�����" << endl;
	sort(v2.begin(), v2.end());
	for (vector<double>::iterator it = v2.begin(); it != v2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	cout << "�����" << endl;
	sort(v2.begin(), v2.end(), greater);
	//sort(v.begin(), v.end(), Greater<int>());
	for (vector<double>::iterator it = v2.begin(); it != v2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){
	test1();


	return 0;
}