//����ģʽ�����ģʽ��һ�֣��䱣֤һ����ֻ��һ��ʵ�������ṩһ��ȫ�ַ��ʵ㣬���ҽ�ֹ����
#include<iostream>
using namespace std;
class Singleton{
public:
	//�����Ұѹ��캯��������private���У�����main�������޷�ʵ��������������public���о���Ҫ����һ���ӿڣ������г�ʼ��
	static Singleton* GetInstance(){
		if (Instance_ == NULL){
			{
				Instance_ = new Singleton;
			}
			return Instance_;
		}
	}

	~Singleton(){
		cout << "~Singleton" << endl;
	}
private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
		//Ϊ�˽�ֹ��������ô����Ҫ���������캯������Ϊ˽�еģ����Ҳ��ṩʵ��
		//Ϊ�˽�ֹ��������ô����Ҫ���Ⱥ����������Ϊ˽�еģ���Ҳ���ṩʵ��

			//ֻ��Ҫ�����캯������Ϊ˽�еģ���ômain�Ͳ��ܵ��ù��캯��
			//��Ȼ�ⲿû������������캯������ô���Ǿ���Ҫ����һ��ȫ�ֵķ��ʵ�
	Singleton(){
		cout << "Singleton..." << endl;
		cout << Instance_ << endl;
	}
	//static void Free(){
	//	if (Singleton::Instance_ != NULL){
	//		delete Instance_;
	//	}
	//Ϊ�˷�ֹ��󲻵����������������ڴ�й©�����ǿ���ѡ��������ʽ������������ʽ�ܲ����㣬��Ҫ�Լ��ֶ�����
	//}
	class Garbo{
	public:
		~Garbo(){
			if (Singleton::Instance_ != NULL){
				delete Instance_;
			}
		}
	};

	static Singleton* Instance_;	//��������
	static Garbo garbo_;	//���ö����ȷ��������������SIngletonʵ�������������������
							//����������garbo_������ݳ�Ա�������ݳ�Ա��Garbon�����͵�
							//garbo_����������һ�������ٵ�������������
};

Singleton* Singleton::Instance_;	//���Ƕ���
Singleton::Garbo Singleton::garbo_;

int main(){
	//Singleton s1;
	//Singleton s2;
	Singleton* s1 =  Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
			//���ǻᷢ��ֻ������һ�ι��캯������Ȼ����������GetInstance��ʵ����ֻ������һ������
			//���û��Garbo�����Ļ����Ͳ��������������

	return 0;
}