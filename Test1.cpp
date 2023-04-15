#include<iostream>
using namespace std;

class Bed{
public:
	Bed(int weight) :weight_(weight){

	}
	void Sleep(){
		cout << "Sleep..." << endl;
	}
	int weight_;
};

class Sofa{
public:
	Sofa(int weight) :weight_(weight){

	}
	void WatchTV(){
		cout << "WatchTV..." << endl;
	}
	int weight_;
};

class SofaBed:public Bed,public Sofa{
public:
	SofaBed() : Bed(0), Sofa(0){
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
	SofaBed sb;
	//sb.weight_ = 39;
	//sb.weight_ = 93;
	//以上的指定是不明确的，应该显示指定

	sb.Bed::weight_ = 93;
	sb.Sofa::weight_ = 39;

	return 0;
}