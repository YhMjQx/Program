#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

//����������ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ͷ֣�ȡƽ����

//����ʵ�֣�
//1.����5��ѡ�֣��ŵ�vector��
//2.����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ������10����ί�Ĵ�ִ�ŵ�deque������
//3.sort�㷨��deque��������ȥ����߷ֺ���ͷ�
//4.deque��������һ�飬�����ܷ�
//5.��ȡƽ����

//ѡ����
class Person{
public:

	Person(string name, int score) :m_Name(name), m_score(score){

	}

	string m_Name;
	int m_score;
};

void creatPerson(vector<Person>&v){
	//��Ҫʹ��forѭ��������
	string namesed = "ABCDE";
	for (int i = 0; i < 5; ++i){

		string name = "ѡ��";
		name += namesed[i];
		//�����ַ���ƴ�Ӽ��ɷֱ��ȡ���ѡ�ֵ�����
		int score = 0;//�����ȶ�Ĭ��Ϊ0

		Person p(name, score);
		//�������ѡ�ּǵý�ѡ�ִ����vector������
		v.push_back(p);
	}
}

void Setscore(vector<Person>&v){
	//����һ��deque�������Դ�ŷ���
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
		//��������Ž�deque����
		deque<int>d;
		//�ܹ���10����ί����˸�forѭ����ʮ��
		for (int i = 0; i < 10; ++i){
			int score = rand() % 41 + 60;
			//rand() % 41 - ������Ϊ0 �� 40
			d.push_back(score);
		}

		//�������Ѿ�ȫ���洢����֮�󣬶�d��������
		sort(d.begin(), d.end());

		////���Դ���
		//cout << "ѡ�֣�" << it->m_Name << " �Ĵ�֣� " << endl;
		//for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit){
		//	cout << *dit << " ";
		//}
		//cout << endl;

		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		//����ƽ����
		int sum = 0;
		for (deque<int>::const_iterator dit = d.begin(); dit != d.end(); ++dit){
			//�ۼ�ÿ����ί�ķ���
			sum += *dit;
		}

		int avg = sum / d.size();

		//������ƽ���ָ�����ѡ�ֵ�����
		it->m_score = avg;
	}
}

void showScore(vector<Person>v){
	for (vector<Person>::iterator it = v.begin(); it != v.end(); ++it){
		cout << "������" << it->m_Name << "  �÷֣�" << it->m_score << endl;
	}
}

int main(){

	//������������
	srand((unsigned int)time(NULL));


	//�������ѡ��
	vector<Person>v1;//���ѡ�ֵ�����
	creatPerson(v1);
	////���Դ���
	//for (vector<Person>::const_iterator it = v1.begin(); it != v1.end(); ++it){
	//	cout << "������ " << (*it).m_Name << "  ������ " << (*it).m_score << endl;
	//}

	//��ѡ�ִ��
	Setscore(v1);

	//���յ÷�
	showScore(v1);

	return 0;
}