#include<iostream>
//友元类是单向的 A是B的友元类（B类中 friend class A）
//友元是不能被传递的。A是B的友元类，B是C的友元类，不代表A也是C的友元类
//友元是不能被继承的。A是B的友元类，C继承自A，不代表C也是B的友元类
using namespace std;
class Television{
	friend class TeleController;
public:
	Television(int volume, int chanel) : volume_(volume), chanel_(chanel){}
private:
	int volume_;//音量
	int chanel_;//频道
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