//const��Ա���������޸Ķ����״̬
//const��Ա����ֻ�ܷ������ݳ�Ա��ֵ���������޸���
//�����һ������ָ��Ϊconst�����Ǹ��߱�������Ҫ�޸���
//const����Ķ��壺const ���� ������(������)
//const�����ܵ��÷�const��Ա����

//��mutable(�ױ�ģ��ɱ��)���ε����ݳ�Ա��ʹ��const�������const��Ա�����ж������޸�

//const ���峣�������ʼ�����������Ҳ�����ʼ��
//const�����ܹ�������const����������ͨ�����þͲ���
//�����У������const��Ա��const��Ա�ĳ�ʼ������ֻ���ڹ��캯����ʼ���б��н���
//const��Ա�������ú��������޸Ķ���״̬��ֻ�ܷ������ݳ�Ա���������޸�

#include<iostream>
using namespace std;
class Test{
public:
	Test(int x) :x_(x), OutputTimes_(0){

	}

	//��const��Ա�������ڶԶ����޸ĵķ���
	int GetX(){
		cout << "Test..." << x_ << endl;
		return x_;//�����x_���Է����ı�
	}

	//const��Ա����
	int GetX() const{
		cout << "const Test..." << x_ << endl;
		return x_;//�����x_���ܷ����ı�
		
	}
	void Output(){
		cout << "x_= " << x_ << endl;
		OutputTimes_++;
	}
	int GetOutputTimes(){
		return OutputTimes_;
	}
private:
	int x_;
	mutable int OutputTimes_;
};
int main(){
	Test t1(39);//����GetX
	const Test t2(10);//����const GetX

	cout << t1.GetX() << endl;//����GetX
	cout<<t2.GetX()<<endl;//����const GetX

	t1.Output();
	t1.Output();
	cout << t1.GetOutputTimes() << endl;
	return 0;
}