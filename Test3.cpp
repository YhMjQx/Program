#include<iostream>
using namespace std;

class Furniture{
public:
	Furniture(int weight) :weight_(weight){
		cout << "Furniture..." << endl;
	}

	~Furniture(){
		cout << "~Furniture..." << endl;
	}
	int weight_;


};
class Bed :virtual public Furniture{
public:
	Bed(int weight) :Furniture(weight){
		cout << "Bed..." << endl;
	}

	~Bed(){
		cout << "~Bed..." << endl;
	}
	void Sleep(){
		cout << "Sleep..." << endl;
	}
};

class Sofa :virtual public Furniture{
public:
	Sofa(int weight) :Furniture(weight){
		cout << "Sofa..." << endl;
	}

	~Sofa(){
		cout << "~Sofa..." << endl;
	}
	void WatchTV(){
		cout << "WatchTV..." << endl;
	}
};

class SofaBed :public Bed, public Sofa{
public:
	SofaBed(int weight) : Bed(weight), Sofa(weight), Furniture(weight)
		//这种情况时，最底层的派生类对所有积累初始化的时候，二其他的基类又是虚基类的派生类
		//此时只会对虚基类进行初始化，对其他基类的初始化代码就被忽略掉了
	{
		cout << "SofaBed..." << endl;
		FoldIn();
	}

	~SofaBed(){
		cout << "~SofaBed..." << endl;
	}
	void FoldOut(){
		cout << "FoldOut..." << endl;
	}

	void FoldIn(){
		cout << "FoldIn..." << endl;
	}


};

int main(){
	SofaBed sb(39);
	sb.weight_ = 93;


	return 0;
}