#include"Clock.h"
//���������Ϊ�˷������﷨�����Է����˸��ļ��ڣ�һ����������Ƕ�Ҫ������Ϊ���̱��
class Object
{
public:
	//��ô������ǲ��ṩĬ�Ϲ��캯����������
	Object(int num) :num_(num)
	{
		cout << "Object " << num_ << endl;
	}
	~Object(){
		cout << "~Object " << num_ << endl;
	}
private:
	int num_;
};
class Container
{
public:
	//������治�ṩĬ�Ϲ��캯����������޷�ִ��
	Container(int obj1 = 0, int obj2 = 0) :obj2_(obj2) , obj1_(obj1)
		//����û�д��Σ������г�ʼ��Ĭ��ֵ��Ҳ���൱�ڸ�obj1��ʼ��Ϊ0����obj2��ʼ��Ϊ0
	{
		cout << "Container ..." << endl;
	}
	~Container(){
		cout << "~Container ..." << endl;
	}
private:
	//������ṩĬ�Ϲ��캯�����ڵ��������ʱ��Ҫ���obj��ʼ����û�а취����ô��ֻ����
	//Container��Ĺ��캯��ֱ�Ӹ�Object��ʼ��
	Object obj1_;
	Object obj2_;
	//���Ƕ����ʼ����˳���빹�캯����ʼ���б��˳���޹�
};
int main(){
	//Clock c(10, 10, 10);
	//c.Display();
	Container c(10,39);
	//��ȻҪ����Container�Ķ����㣬��ô��Ҫ���ö�������ڴ棬���ö����ְ�����
	//Object����࣬���Ծ�Ҫ�ȴ���Object����ഴ���Ķ���
	return 0;
}