#include<iostream>
using namespace std;
//���������static const��Ա��
//����static const��Ա�������ඨ�����г�ʼ��
class Test{
public:
	Test(){

	}
	~Test(){

	}
	static const int num_ = 40;	//��̬��Ա��������˵����ֻ��static const int�͵ĳ�Ա�ſ����������ʼ������ȻcharҲ����
};

//const int Test::num_;	//��̬��Ա�Ķ�����˵��
int main(){
	cout << Test::num_ << endl;
	return 0;
}