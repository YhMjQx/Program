#include<iostream>
using namespace std;
//���������static const��Ա��
//����static const��Ա�������ඨ�����г�ʼ��
class Test{
public:
	Test(int y):y_(y){

	}
	~Test(){

	}

	static void TestStaticFun(){
			//cout << "y_=" << y_ << endl; - error��̬��Ա�������ܷ��ʷǾ�̬��Ա������������
			//��Ϊ��̬��Ա����������thisָ����ָ��ĳ�����󣬶�y_������ĳ������ģ������޷����ʷǾ�̬��Ա
		cout << num_ << endl;//˵����̬��Ա�������Է��ʾ�̬���ݳ�Ա
	}
	void TestFun(){
		cout << "num_=" << num_ << endl;
		//�Ǿ�̬��Ա�������Է��ʾ�̬���ݳ�Ա
		cout << "y_=" << y_ << endl;
	}
	static int num_;	//��̬��Ա��������˵����ֻ��static const int�͵ĳ�Ա�ſ����������ʼ������ȻcharҲ����
	int y_;
};
int Test::num_ = 39;
//const int Test::num_;	//��̬��Ա�Ķ�����˵��
int main(){
	Test::TestStaticFun();
		
	Test t(10);//�������ʼ������t.y_
	t.TestFun();//�Ǿ�̬��Ա���������������������ض����������
	cout << Test::num_ << endl;
	cout<< "sizeof(Test)=" << sizeof(Test) << endl;
	return 0;
}