#include<iostream>
using namespace std;
 
class Base{
public:
	int x_;
protected:
	//�������������з���
	int y_;
private:
	//��ʹ������������Ҳ���ܷ���
	int z_;
};

//���м̳�
class PublicInherit : public Base{
public:
	void Test(){
		x_ = 10;
		y_ = 20;
		//z_ = 30;//z_�ڻ�������private����ô�ڹ��м̳��������಻��ֱ�ӷ���ԭ�����private��Ա
	}
private:
	int a_;
};

//˽�м̳�
//�����еĹ��кͱ�����Ա���������ж������˽�е�,�൱��x_��y_������������private:
class PrivateInherit : private Base{
public:
	void Test(){
		x_ = 10;
		y_ = 20;
		//z_ = 30;// - error
	}
protected:

private:

};

//�����̳�
//�����е�public���ݳ�Ա������������protected��Ա���������е�protected���ݳ�Ա��������������Ҳ��protected
//�����е�private���ݳ�Ա�����������ǲ���ֱ�ӷ��ʵ�
int main(){

	return 0;
}