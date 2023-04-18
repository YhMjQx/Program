#include "Node.h"
#include<cmath>
#include<iostream>


double NumberNode::Calc() const{
	return number_;
}

double AddNode::Calc() const{
	return left_->Calc() + right_->Calc();
}

BinaryNode::~BinaryNode(){
	delete left_;
	delete right_;
}

UnaryNode::~UnaryNode(){

}

double SubNode::Calc() const{
	return left_->Calc() - right_->Calc();
}

double MultiplyNode::Calc() const {
	return left_->Calc() * right_->Calc();
}

double DivideNode::Calc() const{
	//先判断一下除数（分母）是不是0
	double divisor = right_->Calc();
	if (divisor != 0.0)
		return left_->Calc() / divisor;
	else{
		std::cout << "Error:Divisor by zero" << std::endl;
		return HUGE_VAL;
	}
}


double UminusNode::Calc() const{
	return -(child_->Calc());    
}