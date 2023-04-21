#include<iostream>
using namespace std;

//
class MyInteger{
public:
	friend ostream& operator<<(ostream& cout, MyInteger& myint);

	MyInteger(int num) :m_Num(num){

	}

	//����ǰ��++�����
	MyInteger& operator++(){
		//�Ƚ��мӼӲ���
		m_Num++;
		//�ٽ��������ã������أ�Ŀ����Ϊ�˶��++�����ڶ�ͬһ�����ݽ��в���
		//��Ϊ������ص���һ���µĶ�����ôͬʱ�ĵڶ���++�������Ƕ�һ���µĶ�������ݽ��в�����������һֱ��ͬһ������
		return *this;
	}


	//���غ���++�����
	//int - �������һ��ռλ��������������ǰ��++�ͺ���++
	//ע�⣬����Ǻ���++�����ص�һ����һ��ֵ��Ϊʲô�أ�
	//��Ϊ����++��������Ҫ�����Ƿ���һ���ֲ��������Ǻ���++����������
	//��һ�����ص��Ǿֲ�������ôһ�������壬�þֲ�����ͻᱻ���٣�Ȼ�󽫸����ø�������һ��������һ����������ʱ�ֻ�Ըÿռ����٣��ͻᱨ��
	//���ԣ�����һ���������õĶ���ͨ���������캯������һ���µĶ���Ȼ�󷵻�
	MyInteger operator++(int){
		//�� ��¼��ʱ�Ľ��
		MyInteger temp = *this;//��δ++֮ǰ��������temp
		//�� ++����
		m_Num++;
		//��� ����¼�Ľ������
		return temp;
	}
private:
	int m_Num;
};

//�������������
ostream& operator<<(ostream& cout, MyInteger& myint){
	cout << myint.m_Num;
	return cout;
}


void test1(){
	MyInteger myint(0);
	cout << myint << endl;
	cout << ++myint << endl;
	cout << ++(++myint) << endl;
	cout << myint << endl;

}

void test2(){
	MyInteger myint(0);
	cout << myint++ << endl;
	cout << myint << endl;
}


int main(){
	//test1();
	test2();
	return 0;
}