#include<iostream>
using namespace std;


class Cube{
public:
	//设置长宽高
	Cube(){

	}
	Cube(int L, int W, int H) :m_L(L), m_W(W), m_H(H){

	}
	~Cube(){

	}

	//获取长宽高
	int  GetL(){
		return m_L;
	}

	int GetW(){
		return m_W;
	}

	int GetH(){
		return m_H;
	}

	//计算立方体的面积
	int CalcS(){
		return 2 * m_L*m_W + 2 * m_L*m_H + 2 * m_W*m_H;
	}

	//计算立方体体积
	int ClacV(){
		return m_L*m_W*m_H;
	}

	//利用成员函数判断两个立方体是否相等 - 此只用传一个参数，另一个参数就是该类本身，被隐藏了
	bool IsSameByclass(Cube& c){
		if ((m_L == c.GetL()) && (m_W == c.GetW()) && (m_H == c.GetH())){
			return true;
		}
		return false;
	}
private:
	int m_L;//长
	int m_W;//宽
	int m_H;//高
	
};

//利用全局函数判断两个立方体是否相等 - 此时需要传两个参数
bool IsSame(Cube& c1, Cube& c2){
	if ((c1.GetH() == c2.GetH()) && (c1.GetL() == c2.GetL()) && (c1.GetW() == c2.GetW())){
		return true;
	}
	return false;
}
int main(){

	Cube c1(10, 10, 10);
	Cube c2(10, 10, 10);

	cout << c1.CalcS() << endl;
	cout << c1.ClacV() << endl;

	cout << c2.CalcS() << endl;
	cout << c2.ClacV() << endl;

	cout<<IsSame(c1, c2)<<endl;
	cout<<c1.IsSameByclass(c2)<<endl;
	return 0;
}