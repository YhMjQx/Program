//ν�ʸ��
//����bool���͵ķº�����Ϊν��
//���operator()����һ����������ô�ͽ���һԪν��
//���operator()����������������ô�ͽ�����Ԫν��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class FindGreaterFine{
public:
	bool operator()(int val){
		return val > 5;
	}
};

void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	FindGreaterFine fgf;
	vector<int>::iterator pos = find_if(v.begin(), v.end(), fgf);//����ĵ�������������һ��ν��
	//find_if(v.begin(), v.end(), FindGreaterFine());//����ĵ�������������һ��ν��,�����һ��������������

	//find_if�᷵��һ��������,����ҵ��˾ͷ��ظ�λ�õĵ����������û�ҵ��ͷ���end()
	if (pos != v.end()){
		cout << "�ҵ��˴���5�ĵ�һ������Ϊ�� " << *pos << endl;
	}
	else{
		cout << "û�ҵ�����5������" << endl;
	}
}

int main(){
	test1();

	return 0;
}