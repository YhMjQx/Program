#include"Clock.h"
	//���������Ϊ�˷������﷨�����Է����˸��ļ��ڣ�һ����������Ƕ�Ҫ������Ϊ���������
class Object
{
public:
	enum{
		TYPE_A = 100,
		TYPE_B = 200
	};
public:
		//��ô������ǲ��ṩĬ�Ϲ��캯����������
		//const���ݳ�Աֻ�ܷ��ڹ��캯����ʼ���б��н��г�ʼ��
		//���ó�Ա�ĳ�ʼ��Ҳֻ���ڹ��캯���ĳ�ʼ���б��н��г�ʼ��
		//�����Ա����������Ӧ����û��Ĭ�Ϲ��캯�����ĳ�ʼ��Ҳֻ���ڹ��캯���ĳ�ʼ���б��н��г�ʼ��
	Object(int num) :num_(num), KNum_(num), refNum_(num_)
	{
			//KNum_ = num;
			//refNum_ = num;
			//���϶��Ǹ�ֵ�����������ϲ��ǳ�ʼ��
		cout << "Object " << num_ << endl;
	}
	~Object(){
		cout << "~Object " << num_ << endl;
	}
	void KNumDisplay(){
		cout << "KNum_= " << KNum_ << endl;
	}
private:
	int num_;
	const int KNum_;
		//���const����ֻ���ഴ����һ�����������㳣��������
		//Ϊ�����첻�����ഴ�����ĸ������ж����㳣�������ʵ����ݣ����ǿ���ʹ��ö�ٳ���
	int& refNum_;
		//��num_������refNum_,��refNum_�������ĸı���Ƕ�num_�ĸı�
};
int main(){
	Object obj1(39);
	Object obj2(10);
	obj1.KNumDisplay();
	obj2.KNumDisplay();
		//������obj1�����KNum_��39������obj2�����KNum_�Ͳ���39

	cout << Object::TYPE_A << endl;
	cout << Object::TYPE_B << endl;
	cout << obj1.TYPE_A << endl;
	cout << obj1.TYPE_B << endl;
	cout << obj2.TYPE_A << endl;
	cout << obj2.TYPE_B << endl;
		//������������ö�ٳ����Ļ���������obj1����obj2���ܷ���ö�ٳ���
	return 0;
}