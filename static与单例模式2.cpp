//����ģʽ�����ģʽ��һ�֣��䱣֤һ����ֻ��һ��ʵ�������ṩһ��ȫ�ַ��ʵ㣬���ҽ�ֹ����
//ʵ���������ģʽ�������̲߳���ȫ
//��Ĭ�Ϲ��캯����Ϊ˽�е�,��ʱ��Ҫ�趨һ��ȫ�ֵĽӿڣ���ֹ��������ֹ��ֵ
#include<iostream>
using namespace std;
class Singleton{
public:
	//�����Ұѹ��캯��������private���У�����main�������޷�ʵ��������������public���о���Ҫ����һ���ӿڣ������г�ʼ��

	//��������
	static Singleton& GetInstance(){
		static Singleton Instance;	//�ֲ���̬����
		return Instance;
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

	Singleton(){
		cout << "Singleton..." << endl;
	}

};


int main(){
		//����������ǲ���ʡ�Ե�
	Singleton& s1 = Singleton::GetInstance();
	Singleton& s2 = Singleton::GetInstance();
		//��Ȼ����������GetInstance������ֻ������һ������

	return 0;
}