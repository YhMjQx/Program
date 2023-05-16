//�㷨��Ҫ����ͷ�ļ�<algorithm><functional><numeric>���
//<algorithm>������STLͷ�ļ�������һ������Χ�漰���Ƚϣ����������ң����������ƣ��޸ĵȵ�
//<numeric>�����С��ֻ��������������������м���ѧ�����ģ�庯��
//<functional>������һЩģ���࣬����������������
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Print1(int val){
	cout << val << " ";
}

class Print2{
public:
	void operator()(int val){
		cout << val << " ";
	}
};

class Transform{
public:
	int operator()(int v){
		return v + 39;
	}
};

void test1(){
	vector<int>v;

	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print1);
	cout << endl;
	for_each(v.begin(), v.end(), Print2());
	cout << endl;

	vector<int>vTarget;

	vTarget.resize(v.size());
	
	//transform( ԭ������ʼλ�ã�ԭ��������λ�ã�Ŀ��������ʼλ�ã�ӳ�䷽ʽ(�����мӼ��˳�ȡ��֮��ģ���Щ�����ڽ���������))
	transform(v.begin(),v.end(), vTarget.begin(), Transform());
	for_each(vTarget.begin(), vTarget.end(), Print1);
	cout << endl;

}

int main(){
	test1();
	
	return 0;
}