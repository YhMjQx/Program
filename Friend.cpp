//��Ԫ��һ������ �����Ա���� ���� ��ķǹ��г�Ա ��һ�ֻ���
//���԰�һ������ָ��Ϊ�����Ԫ - ��Ԫ������Ҳ���԰�������ָ��Ϊ��һ�������Ԫ - ��Ԫ�ࡣ
//
//1.��Ԫ����������������ⶨ�壬������Ҫ�������н���˵��
//2.Ϊ�������ĳ�Ա�����������𣬶���ķ�ʽ���������ùؼ���friend˵���ú���
//��ʽ���£�friend ���� ��Ԫ������(������)
//��Ԫ������������߳��������Ч��
#include<iostream>
#include<math.h>
using namespace std;
class Point{
public:
	Point(int x, int y) :x_(x), y_(y){}		//���캯��

	friend double Distence(const Point& p1, const Point& p2);		//��Ԫ������������ĳ�Ա����
private:
	int x_;
	int y_;
};

//������������ⶨ��
double Distence(const Point& p1, const Point& p2){
	double dx = p1.x_ - p2.x_;
	double dy = p1.y_ - p2.y_;
	//���ǻᷢ�֣��������Ԫ�������ڿ���ֱ�Ӷ����˽�г�Աֱ�ӷ���

	return sqrt(dx * dx + dy * dy);
}
int main(){
	Point p1(3, 4);
	Point p2(6, 8);
	cout<<Distence(p1, p2)<<endl;
	return 0;
}