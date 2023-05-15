#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<time.h>
using namespace std;

//��˾������Ƹ10��Ա����ABCDEFGHIJ����10��Ա�����빫˾����Ҫָ��Ա�����ĸ����Ź���
//Ա����Ϣ�У����� ����   ���ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ���� key�����ű�ţ� value��Ա����
//�ֲ�����ʽԱ����Ϣ

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker{
public:
	string m_Name;
	int m_Salary;
};

void createPerson(vector<Worker>& v){

	string nameseed = "ABCDEFGHIJ";

	for (int i = 0; i <10; ++i){
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameseed[i];

		worker.m_Salary = rand() % 10000 + 10000;

		//ÿ������һ��Ա����Ӧ�ý����Ž�vector������
		v.push_back(worker);
	}
}

void SetGroup(vector<Worker>& v,multimap<int ,Worker>& m){
	//�ȱ���һ��v���������������Ľ�����з���
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); ++it){
		//���ȣ������ȴ���һ����������ű��

		int deptId = rand() % 3;// 0 1 2

		m.insert(make_pair(deptId, *it));
		//���ھ���Ҫ��ÿһ��Ա�����Լ�����Ӧ�Ĳ��ű�ţ�����multimap������
		//���Ǳ����ˣ�map��multimap�����ڵ�����Ԫ�ض��Ƕ��飬��ô���Ǵ���ȥ��ҲӦ���Ƕ������
		//����ʹ��vector�������������飬����*it�ʹ������Worker

		//������vector������˳���ǰ���ABCDEFGHIJ������ģ���Ϊʲô����multimap������˳��Ͳ�һ������
		//ԭ������Ϊ��vector�е�ȷ������ģ����������ʱ��Ҳ��ȷ������Ĵ�A��Jһһ�����ģ���multimap�в����ʱ��Ҳ�������
		//���ǹؼ�����deptId���ǲ�ͣ���ڱ�ģ�Ҳ����˵A��Ӧ��depeId�ǿ�����0������һ��B��Ӧ��deptId���ܾͱ��2��
		//Ȼ��ͻ��ÿһ��deptId��������Ҳ�Ƕ�keyֵ����Ҳ����󿴵��Ľ����
	}
}

void ShowWorker(multimap<int,Worker>& m){
	cout << "�߻����ţ�" << endl;
	//�ҵ�keyֵΪ0��Ա����,���õ����������Լ������ݼ���
	multimap<int, Worker>::iterator pos = m.find(CEHUA);//�ҵ�keyֵΪ0����ʼλ��
	int index = m.count(CEHUA);//ͳ��keyֵΪ0���ܹ�����
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "���ű�ţ�" << pos->first << "  ������" << pos->second.m_Name << "  ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;

	cout << "��������" << endl;
	pos = m.find(MEISHU);//�ҵ�keyֵΪ1����ʼλ��
	index = m.count(MEISHU);//ͳ��keyֵΪ1���ܹ�����
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "���ű�ţ�" << pos->first << "  ������" << pos->second.m_Name << "  ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;

	cout << "�з�����" << endl;
	pos = m.find(YANFA);//�ҵ�keyֵΪ2����ʼλ��
	index = m.count(YANFA);//ͳ��keyֵΪ2���ܹ�����
	for (int count = 0; pos != m.end() && count < index; ++pos, ++count){
		cout << "���ű�ţ�" << pos->first << "  ������" << pos->second.m_Name << "  ���ʣ�" << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------------" << endl;
}

void test1(){

	//1.����Ա������Ž�����
	vector<Worker>vworker;//�ȴ���һ�����Person���������ý�������Person��Ž�������
	createPerson(vworker);

	////����
	//for (vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); ++it){
	//	cout << "������" << (*it).m_Name << "  ���䣺" << it->m_Salary << endl;
	//}
	//cout << "-------------------------" << endl;

	//2.Ա������
	multimap<int, Worker>mworker;
	//key - ���ű��    value - Worker����Ա��       �����յ�Ŀ�ľ��ǽ�����Ա���Լ���Ӧ��������Ϣ����������multimap������
	SetGroup(vworker, mworker);
	//Ҫ���Ա�����з��飬��ô����Ҫ�����е�Ա���Ž�ȥ�����������е�Ա���ʹ����vworker�У����Ե�һ����������vworker
	//������������Ҫ��key �� value�ķ�ʽ���з��飬���Ծ���Ҫ�õ�multimap�������������Ǿʹ���һ��mworker


	////����
	//for (multimap<int, Worker>::iterator it = mworker.begin(); it != mworker.end(); ++it){
	//	cout << "���ű�ţ�" << it->first << "  ������" << it->second.m_Name << "  ���ʣ�" << it->second.m_Salary << endl;
	//}
	//cout << "-------------------------" << endl;


	//3.������ʾԱ��
	//��Ϊ����Ա����Ӧ��������Ϣȫ����mworker���У���������Ӧ�ý�mworker��Ϊ��������ȥ
	ShowWorker(mworker);
}

int main(){
	srand((unsigned int)time(NULL));
	test1();

	return 0;
}