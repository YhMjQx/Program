#include<iostream>
#include<map>
using namespace std;

//find(key); -- ����key�Ƿ��Ѿ����ڣ����ظü���Ԫ�صĵ��������������ڣ�����map.end();
//count(key); -- ͳ��key��Ԫ�ظ���

void Printmap(map<int, int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "keyֵ��" << (*it).first << " valueֵ��" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//����һ��map����
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(5, 50));


	map<int,int>::iterator pos = m.find(3);//����keyֵΪ3 ��Ԫ��
	if (pos != m.end()){
		cout << "�ҵ���Ԫ�� key= " << (*pos).first << " value= " << pos->second << endl;
	}
	else{
		cout << "û�ҵ�" << endl;
	}

	//ͳ��
	cout<<"ͳ�Ƶ� "<<m.count(5)<<" ��keyΪ5��Ԫ��"<<endl;//�������1
	//˵��mapҲ�ǲ��������keyֵ��ͬ��Ԫ�أ����Զ���map������˵count���ֻ��0��1
	//��ôcountһ�������multimap������


}

int main(){
	test1();

	return 0;
}