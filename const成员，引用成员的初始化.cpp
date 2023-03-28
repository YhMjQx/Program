#include"Clock.h"
	//下面的类是为了方便检测语法，所以放在了该文件内，一般情况下我们都要将它分为工程来编程
class Object
{
public:
	enum{
		TYPE_A = 100,
		TYPE_B = 200
	};
public:
		//那么如果我们不提供默认构造函数会怎样呢
		//const数据成员只能放在构造函数初始化列表中进行初始化
		//引用成员的初始化也只能在构造函数的初始化列表当中进行初始化
		//对象成员（对象所对应的类没有默认构造函数）的初始化也只能在构造函数的初始化列表当中进行初始化
	Object(int num) :num_(num), KNum_(num), refNum_(num_)
	{
			//KNum_ = num;
			//refNum_ = num;
			//以上都是赋值操作，本质上不是初始化
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
		//这个const常量只在类创建的一个对象中满足常量的性质
		//为了制造不论在类创建的哪个对象中都满足常量的性质的数据，我们可以使用枚举常量
	int& refNum_;
		//将num_引用至refNum_,对refNum_所做出的改变就是对num_的改变
};
int main(){
	Object obj1(39);
	Object obj2(10);
	obj1.KNumDisplay();
	obj2.KNumDisplay();
		//这上面obj1里面的KNum_是39，但是obj2里面的KNum_就不是39

	cout << Object::TYPE_A << endl;
	cout << Object::TYPE_B << endl;
	cout << obj1.TYPE_A << endl;
	cout << obj1.TYPE_B << endl;
	cout << obj2.TYPE_A << endl;
	cout << obj2.TYPE_B << endl;
		//但是在这里用枚举常量的话，不管是obj1还是obj2都能访问枚举常量
	return 0;
}