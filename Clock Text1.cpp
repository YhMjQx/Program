#include"Clock.h"
//���������Ϊ�˷������﷨�����Է����˸��ļ��ڣ�һ����������Ƕ�Ҫ������Ϊ���̱��
class Object
{
public:
	Object() 
	{
		cout << " ... Object ... " << endl;
	}
	~Object(){
		cout << " ... ~Object ..." << endl;
	}
private:
	int num_;
};
class Container
{
public:
	//������治�ṩĬ�Ϲ��캯����������޷�ִ��
	Container(){
		cout << " ... Container ..." << endl;
	}
	~Container(){
		cout << " ... ~Container ..." << endl;
	}
private:
	//����һ���������
	Object obj_;
};
int main(){
	//Clock c(10, 10, 10);
	//c.Display();
	Container c;
	//��ȻҪ����Container�Ķ����㣬��ô��Ҫ���ö�������ڴ棬���ö����ְ�����
	//Object����࣬���Ծ�Ҫ�ȴ���Object����ഴ���Ķ���
	return 0;
}