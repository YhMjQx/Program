#include "Integer.h"


Integer::Integer(int n) : n_(n)
{
}


Integer::~Integer()
{
}

void Integer::Display(){
	cout << "n_= " << n_ << endl;
}

Integer& Integer::operator++(){
	++n_;
	cout << "Integer& Integer::operator++()" << endl;
	return *this;
}

////Ҫ��ס����Ԫ����������ĳ�Ա���������Բ���Ҫ�������������
//Integer& operator++(Integer& i){
//	cout << "Integer& operator++()" << endl;
//	++i.n_;
//	return i;
//}

Integer Integer::operator++(int i){
	cout << "Integer& Integer::operator++()" << endl;

	////n_++;
	////return *this;
	////����++��ôд�Ǵ�ģ����Ҫ����д�Ļ�����ôn_��++�˲Ż᷵�س�ȥ��Ȼ��ֵ���µĶ���֮��n_��++����Ͳ���������Ҫ�Ľ����
	////��������������Ҫ���ص����ã����⿽�����캯���ĵ��ã���ô����ô�����������أ�������Ҫ�õ���ʱ����,��ʱ�Ͳ��ܷ��������ˣ����Ƿ���һ����
	Integer tmp(n_);//��n_����tmp���������ô��ʱ���tmp�����е�n_��û�б�++����
	n_++;//Ȼ���n_��������++
	return tmp;
	//������������++�������ʽ�Ľ����û��++����Ϊ�ҷ��ص���û��++�Ķ���
	//Ϊʲô���ﲻ���������أ���Ϊ��tmp����ʱ�����һ�������ž�ֱ�������ˣ��������᷵��
}

//Integer operator++(Integer& i, int n){
//	Integer tmp(i.n_);
//	i.n_++;
//	return tmp;
//}