#include<iostream>
//��Ԫ���ǵ���� A��B����Ԫ�ࣨB���� friend class A��
//��Ԫ�ǲ��ܱ����ݵġ�A��B����Ԫ�࣬B��C����Ԫ�࣬������AҲ��C����Ԫ��
//��Ԫ�ǲ��ܱ��̳еġ�A��B����Ԫ�࣬C�̳���A��������CҲ��B����Ԫ��
using namespace std;
class Television{
	friend class TeleController;
public:
	Television(int volume, int chanel) : volume_(volume), chanel_(chanel){}
private:
	int volume_;//����
	int chanel_;//Ƶ��
};

class TeleController{
public:
	void VolumeUp(Television& tv){
		tv.volume_ += 1;
	}

	void VolumeDown(Television& tv){
		tv.volume_ = 1;
	}

	void ChanelUp(Television& tv){
		tv.chanel_ += 1;
	}

	void ChanelDown(Television& tv){
		tv.chanel_ -= 1;
	}
private:

};
int main(){

	return 0;
}