#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>& L){
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	//����һ��list����
	list<int>L1;

	//�������
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	PrintList(L1);

	//list<int>::const_iterator it = L1.begin();
	//it = it + 2;
	//it += 2;
	//it = L1.begin()+2;
	//���⼸�����Ϳ���֪����it���ԼӼӣ���������Ծʽ�Ӽ�


	//������ʽ����
	list<int>L2(L1.begin(), L1.end());
	PrintList(L2);

	//��������
	list<int >L3(L1);
	PrintList(L3);

	//n��elem����ʽ����
	list<int>L4(10, 39);
	PrintList(L4);


}

int main(){
	test1();

	return 0;
}