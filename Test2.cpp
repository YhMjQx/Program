#include<iostream>
using namespace std;


//����һ��û���κνӿڵ��࣬�����Ҫ��������Ϊ�����ֻ࣬�ܽ���������������Ϊ������������
//ͨ��������ڻ����еĴ��麯���ǲ���Ҫʵ�ֵģ����Ǵ�������������ֻ���ø���һ���յ�ʵ�ּ��ɣ����Ǹ�����
class Base{
public:
	virtual ~Base() = 0
	{
		cout << "virtual ~Base() = 0" << endl;
	}
};

class Drived :public Base{

};
int main(){
	Drived d;
	return 0;
}