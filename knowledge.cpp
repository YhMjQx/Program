//map�������
//��飺
//map�е�����Ԫ�ض���pair
//pair�еĵ�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue(ʵֵ)
//����Ԫ�ض������Ԫ�صļ�ֵ����
//����;
//map/multimap - ���ڹ���ʽ�������ײ��ö�����ʵ��
//�ŵ㣺
//���Ը���keyֵ�����ҵ�valueֵ
//map��multimap������
//map���������������ظ�keyֵԪ��
//multimap�������������ظ�keyֵԪ��
#include<iostream>
#include<map>
using namespace std;

void Printmap(map<int,int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "keyֵ��" << (*it).first << " valueֵ��" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//����һ��map����
	map<int, int> m;

	//�����key��ֵ�Զ���������������
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(5, 50));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	
	Printmap(m);

	//�������죬�൱����һ�ֳ�ʼ��
	map<int, int> m2(m);
	Printmap(m2);

	//ֱ�Ӹ�ֵ
	map<int, int>m3;
	m3 = m;
	Printmap(m2);

}

int main(){
	test1();

	return 0;
}