#include<iostream>
using namespace std;

//����
class Point{
public:
	//���õ������
	Point(int x, int y) :m_X(x), m_Y(y){

	}
	//��ȡ��ĺ�����
	int GetX(){
		return m_X;
	}
	//��ȡ���������
	int GetY(){
		return m_Y;
	}
private:
	int m_X;
	int m_Y;

};


//Բ��
class Circle{
public:
	//����Բ�İ뾶��Բ��
	Circle(int r, Point& p) :m_R(r), m_Center(p){

	}

	//��ȡԲ�İ뾶
	int GetR(){
		return m_R;
	}

	//��ȡԲ��
	Point GetCenter(){
		return m_Center;
	}
private:
	int m_R;
	Point m_Center;
};

//��ȫ�ֺ������жϵ��Բ��λ�ù�ϵ
void WherePointCircle(Circle& c,Point& p){
	//�������Բ��֮��ľ����ƽ��
	int ret = ((c.GetCenter().GetX() - p.GetX()) *(c.GetCenter().GetX() - p.GetX())) +
		((c.GetCenter().GetY() - p.GetY())*(c.GetCenter().GetY() - p.GetY()));
	//����뾶��ƽ��
	int R = c.GetR()*c.GetR();
	if (ret == R){
		cout << "����Բ��" << endl;
	}
	else if (ret < R){
		cout << "����Բ��" << endl;
	}
	else{
		cout << "����Բ��" << endl;
	}
}
int main(){
	//����Բ
	//��һ��Բ��
	Point center(10, 0);
	//����Բ�İ뾶
	Circle c(10,center);

	//����һ����
	Point p(10,10);

	//�жϹ�ϵ
	WherePointCircle(c, p);
	return 0;
}