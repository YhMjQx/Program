#include<iostream>
using namespace std;

//计算机有三个零件构成，但有不同的厂商，inter可以制造这三个零件，lenovo也可以制造这三个零件
//所以这三个零件应该作为抽象类才可以，因为不同的厂商有不同的行为模式，然后让每个厂商对应的部门分别继承这三个抽象类
//然后实现相对应的功能，然后用一个电脑类作为一个总的电脑，将三个零件都包含在内
//最后只用这个电脑类来组装完整的电脑。

class CPU{
public:
	//抽象的计算函数
	virtual void calculate() = 0;
};

class VideoCard{
public:
	//抽象的显示函数
	virtual void Display() = 0;
};

class Memory{
public:
	//抽象的存储函数
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
		//让零件工作起来，调用接口
		m_cpu->calculate();
		m_vc->Display();
		m_mem->storage();
	}

	//由于三个零件也是在堆区开辟的，所以应该使用一个析构代码将这三个零件的指针也释放掉
	//因为单单释放父类指针无法将这三个零件的指针一同释放
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

//具体厂商
//Inter厂商
class InterCPU :public CPU{
public:

	void calculate(){
		cout << "Inter的CPU开始计算了！" << endl;
	}
};
class InterVideoCard :public VideoCard{
public:

	void Display(){
		cout << "Inter的VideoCard开始显示了！" << endl;
	}
};
class InterMemory :public Memory{
public:

	void storage(){
		cout << "Inter的Memory开始存储了！" << endl;
	}
};



//lenovo厂商
class lenovoCPU :public CPU{
public:

	void calculate(){
		cout << "lenovo的CPU开始计算了！" << endl;
	}
};
class lenovoVideoCard :public VideoCard{
public:

	void Display(){
		cout << "lenovo的VideoCard开始显示了！" << endl;
	}
};
class lenovoMemory :public Memory{
public:

	void storage(){
		cout << "lenovo的Memory开始存储了！" << endl;
	}
};


void test1(){
	//父类指针创建子类对象
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