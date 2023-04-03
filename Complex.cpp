#include "Complex.h"


Complex::Complex(int real, int imag) : real_(real), imag_(imag)
{
}


Complex::Complex()
{
}


Complex::~Complex()
{
}


void Complex::Display(){
	cout << real_ << "+" << imag_ << "i" << endl;
}

Complex& Complex::Add(const Complex& other){
	real_ += other.real_;
	imag_ += other.imag_;

	return *this;
}

Complex Complex::operator+(const Complex& other){
	int r = real_ + other.real_;
	int i = imag_ + other.imag_;

	return Complex(r, i);
}
Complex operator+(const Complex& other1, const Complex& other2){
	int r = other1.real_ + other2.real_;
	int i = other1.imag_ + other2.imag_;
	return Complex(r, i);
}
//成员函数的重载优先于友元重载