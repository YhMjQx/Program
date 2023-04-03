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

////要记住，友元函数不是类的成员函数，所以不需要类名和域操作符
//Integer& operator++(Integer& i){
//	cout << "Integer& operator++()" << endl;
//	++i.n_;
//	return i;
//}

Integer Integer::operator++(int i){
	cout << "Integer& Integer::operator++()" << endl;

	////n_++;
	////return *this;
	////后置++这么写是错的，如果要这样写的话，那么n_先++了才会返回出去，然后赋值给新的对象，之后n_在++，这就不是我们想要的结果了
	////而且这样做是需要返回的引用，避免拷贝构造函数的调用，那么该怎么解决这个问题呢，我们需要用到临时对象,此时就不能返回引用了，而是返回一个类
	Integer tmp(n_);//把n_赋给tmp这个对象，那么此时这个tmp对象中的n_是没有被++过的
	n_++;//然后把n_放在这里++
	return tmp;
	//最后就满足自身++，但表达式的结果并没有++，因为我返回的是没有++的对象
	//为什么这里不能用引用呢，因为，tmp是临时类对象，一出花括号就直接销毁了，根本不会返回
}

//Integer operator++(Integer& i, int n){
//	Integer tmp(i.n_);
//	i.n_++;
//	return tmp;
//}