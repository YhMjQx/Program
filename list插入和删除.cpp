#include<iostream>
#include<list>
using namespace std;

//push back(elem);//������β������һ��Ԫ��pop_back0;//ɾ�����������һ��Ԫ��
//push front(elem) ://��������ͷ����һ��Ԫ��
//pop_front0 ://��������ͷ�Ƴ���һ��Ԫ��
//insert(pos, elem) ://��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
//insert(pos, n, elem) ://��posλ�ò���n��elem���ݣ��޷���ֵ��
//insert(pos, beg, end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ
//clear()://�Ƴ���������������
//erase(beg,end)://ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ��
//erase(pos)://ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
//remove(elem)://ɾ��������������elemֵƥ���Ԫ�ء�


void Printlist(list<int>&L){
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	list<int>L1;
	
	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	Printlist(L1);

	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	Printlist(L1);

	//ͷɾ
	L1.pop_front();
	//βɾ
	L1.pop_back();
	Printlist(L1);

	//insert����
	list<int>::iterator it = L1.begin();
	L1.insert(it++, 39);
	Printlist(L1);
	//ɾ��
	--it;//ԭ����it�ڲ���֮����ָ�����֮ǰ��λ�ã�Ҳ����˵��ʹ������Ԫ�أ���it��ָ�򲢲���
	L1.erase(it);
	Printlist(L1);

	//�Ƴ���ͬ������
	L1.push_back(2000);
	L1.push_back(2000);
	L1.push_back(2000);
	Printlist(L1);
	L1.remove(2000);
	Printlist(L1);

	//���
	L1.clear();
	Printlist(L1);


}

int main(){
	test1();

	return 0;
}