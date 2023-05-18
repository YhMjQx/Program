#include<iostream>
using namespace std;

//�����������������ɣ����в�ͬ�ĳ��̣�inter�������������������lenovoҲ�����������������
//�������������Ӧ����Ϊ������ſ��ԣ���Ϊ��ͬ�ĳ����в�ͬ����Ϊģʽ��Ȼ����ÿ�����̶�Ӧ�Ĳ��ŷֱ�̳�������������
//Ȼ��ʵ�����Ӧ�Ĺ��ܣ�Ȼ����һ����������Ϊһ���ܵĵ��ԣ��������������������
//���ֻ���������������װ�����ĵ��ԡ�

class CPU{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};

class VideoCard{
public:
	//�������ʾ����
	virtual void Display() = 0;
};

class Memory{
public:
	//����Ĵ洢����
	virtual void storage() = 0;
};

class Computer{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem){
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work(){
		//������������������ýӿ�
		m_cpu->calculate();
		m_vc->Display();
		m_mem->storage();
	}

	//�����������Ҳ���ڶ������ٵģ�����Ӧ��ʹ��һ���������뽫�����������ָ��Ҳ�ͷŵ�
	//��Ϊ�����ͷŸ���ָ���޷��������������ָ��һͬ�ͷ�
	~Computer(){
		if (m_cpu != NULL){
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL){
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL){
			delete m_mem;
			m_mem = NULL;
		}
	}


private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

//���峧��
//Inter����
class InterCPU :public CPU{
public:

	void calculate(){
		cout << "Inter��CPU��ʼ�����ˣ�" << endl;
	}
};
class InterVideoCard :public VideoCard{
public:

	void Display(){
		cout << "Inter��VideoCard��ʼ��ʾ�ˣ�" << endl;
	}
};
class InterMemory :public Memory{
public:

	void storage(){
		cout << "Inter��Memory��ʼ�洢�ˣ�" << endl;
	}
};



//lenovo����
class lenovoCPU :public CPU{
public:

	void calculate(){
		cout << "lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};
class lenovoVideoCard :public VideoCard{
public:

	void Display(){
		cout << "lenovo��VideoCard��ʼ��ʾ�ˣ�" << endl;
	}
};
class lenovoMemory :public Memory{
public:

	void storage(){
		cout << "lenovo��Memory��ʼ�洢�ˣ�" << endl;
	}
};


void test1(){
	//����ָ�봴���������
	CPU* cpu = new InterCPU;
	VideoCard* vc = new InterVideoCard;
	Memory* mem = new InterMemory;

	Computer* intercomputer = new Computer(cpu, vc, mem);
	intercomputer->work();
	delete intercomputer;

	cout << "--------------------------" << endl;

	cpu = new lenovoCPU;
	vc = new lenovoVideoCard;
	mem = new lenovoMemory;

	Computer* lenovocomputer = new Computer(cpu, vc, mem);
	lenovocomputer->work();
	delete lenovocomputer;

}


int main(){
	test1();
	return 0;
}