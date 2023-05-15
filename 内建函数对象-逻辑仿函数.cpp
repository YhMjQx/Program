#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

//template<class T> bool logical_and<T>	//�߼���
//template<class T> bool logical_or<T>	//�߼���
//template<class T> bool logical_not<T>	//�߼���


void test1(){
	vector<bool>v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

	//��v1����ӳ�䵽v2�������У��������߼��ǵķ�ʽӳ��
	//����vector�е���������boolֵ�����ģ�����logical_not<bool>����ҲҪ��bool
	//�ص��ص��ص㣡����
	//��transform֮ǰһ��Ҫ��v2���ٺ�Ӧ�еĿռ�,����ֱ�ӽ����ݿ���ȥ���൱�ڸ����˲������Լ��Ŀռ䣬�зǷ�����
	vector<bool>v2;
	v2.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;

}

int main(){
	test1();

	return 0;
}