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

void Printmap(map<int, int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "keyֵ��" << (*it).first << " valueֵ��" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//����һ��map����
	map<int, int> m;

	//����
	//��һ�֣�
	m.insert(pair<int, int>(1, 10));

	//�ڶ���
	m.insert(make_pair(2, 20));

	//������
	m.insert(map<int, int>::value_type(3, 30));

	//������
	//[]�ķ�ʽ���������������룬��������������
	m[4] = 40;
	//cout << m[4] << endl;
	//cout << m[5] << endl;//��������ͻ��ȴ���keyֵΪ5��Ԫ�أ�Ȼ�������Ԫ�ص�valueֵ
	//ʵ����m�����в�û��keyֵΪ5��Ԫ�أ���������Ҫ��ӡ�����ͻ���Ҵ���һ��keyֵΪ5��Ԫ�أ�������0��Ϊvalueֵ

	Printmap(m);

	//ɾ��
	m.erase(m.begin());
	Printmap(m);

	m.erase(4);//ע�⣬�����ǰ���keyֵ��ɾ��
	Printmap(m);

	//m.erase(m.begin(), m.end());//���
	m.clear();
	Printmap(m);

}

int main(){
	test1();

	return 0;
}