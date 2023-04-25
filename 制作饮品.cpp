#include<iostream>
using namespace std;

class AbstractDrinking{
public:
	//煮水
	virtual void Boil() = 0;

	//冲泡
	virtual void Brew() = 0;

	//倒入杯中
	virtual void PourInCup() = 0;

	//加入作料
	virtual void PutSomething() = 0;

	//制作饮品
	void makeDrink(){
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class makeCoffe:public AbstractDrinking{
public:
	//煮水
	virtual void Boil(){
		cout << "煮巴黎水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "冲泡猫屎咖啡" << endl;
	}

	//倒入杯中
	virtual void PourInCup(){
		cout << "倒入咖啡杯" << endl;
	}

	//加入作料
	virtual void PutSomething(){
		cout << "加入糖和牛奶" << endl;
	}
};

//做柠檬枸杞茶
class makeTee:public AbstractDrinking{
public:
	//煮水
	virtual void Boil(){
		cout << "煮巴黎水" << endl;
	}

	//冲泡
	virtual void Brew() {
		cout << "冲泡顶尖纤毫" << endl;
	}

	//倒入杯中
	virtual void PourInCup(){
		cout << "倒入茶杯" << endl;
	}

	//加入作料
	virtual void PutSomething(){
		cout << "加入柠檬片和枸杞" << endl;
	}
};

void dowork(AbstractDrinking* abd){
	abd->makeDrink();
	delete abd;//注意，堆区上开辟的空间一定要记得释放
}

//做咖啡测试
void test1(){
	dowork(new makeCoffe);
}

//做柠檬枸杞茶测试
void test2(){
	dowork(new makeTee);

}
int main(){
	test1();
	cout << "-------------" << endl;
	test2();
	return 0;
}