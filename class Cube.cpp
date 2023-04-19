#include<iostream>
using namespace std;


class Cube{
public:
	//���ó����
	Cube(){

	}
	Cube(int L, int W, int H) :m_L(L), m_W(W), m_H(H){

	}
	~Cube(){

	}

	//��ȡ�����
	int  GetL(){
		return m_L;
	}

	int GetW(){
		return m_W;
	}

	int GetH(){
		return m_H;
	}

	//��������������
	int CalcS(){
		return 2 * m_L*m_W + 2 * m_L*m_H + 2 * m_W*m_H;
	}

	//�������������
	int ClacV(){
		return m_L*m_W*m_H;
	}

	//���ó�Ա�����ж������������Ƿ���� - ��ֻ�ô�һ����������һ���������Ǹ��౾����������
	bool IsSameByclass(Cube& c){
		if ((m_L == c.GetL()) && (m_W == c.GetW()) && (m_H == c.GetH())){
			return true;
		}
		return false;
	}
private:
	int m_L;//��
	int m_W;//��
	int m_H;//��
	
};

//����ȫ�ֺ����ж������������Ƿ���� - ��ʱ��Ҫ����������
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