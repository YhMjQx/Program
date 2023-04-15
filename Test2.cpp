#include<iostream>
using namespace std;

class Furniture{
public:
	Furniture(int weight) :weight_(weight){

	}
	int weight_;
	

};
class Bed:public Furniture{
public:
	Bed(int weight) :Furniture(weight){

	}
	void Sleep(){
		cout << "Sleep..." << endl;
	}
};

class Sofa: public Furniture{
public:
	Sofa(int weight) :Furniture(weight){

	}
	void WatchTV(){
		cout << "WatchTV..." << endl;
	}
};

class SofaBed :public Bed, public Sofa{
public:
	SofaBed(int weight) : Bed(weight), Sofa(weight){
		FoldIn();
	}

	void FoldOut(){
		cout << "FoldOut..." << endl;
	}

	void FoldIn(){
		cout << "FoldInt..." << endl;
	}


};

int main(){
	SofaBed sb(100);
	//sb.weight_ = 39;
	//sb.weight_ = 93;
	//以上的指定是不明确的，应该显示指定

	sb.Bed::weight_ = 93;
	sb.Sofa::weight_ = 39;

	return 0;
}