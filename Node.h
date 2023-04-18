#ifndef _NODE_H_
#define _NODE_H_


class Node
{
public:
	//抽象类中需要将析构函数定义为纯虚函数，否则delete基类指针时，不会调用基类的析构函数
	virtual double Calc() const = 0;
	virtual ~Node();

};

class NumberNode :public Node{
public:
	NumberNode(double number) :number_(number){}
	double Calc() const;
private:
	const double number_;
};


//二元运算节点,这个还是一个抽象类，因为他根本不知道该如何具体地进行运算，只有加减乘除才是具体的
class BinaryNode :public Node{
public:
	BinaryNode(Node* left, Node* right) :left_(left), right_(right){}

	~BinaryNode();
protected:
	Node* const left_;
	Node* const right_;
};

//一元运算节点
class UnaryNode :public Node{
public:
	UnaryNode(Node* child) :child_(child){}
	~UnaryNode();
	//释放孩子这个数据成员
	//此时，他继承自Node，其中的Calc还是纯虚的，说明如果不是实现这个函数的Calc函数，这个类也是抽象类
protected:
	Node* const child_;
};


//AddNode继承自BinaryNode，它的构造函数要调用基类的构造函数
class AddNode :public BinaryNode{
public:
	AddNode(Node* left, Node* right) : BinaryNode(left, right){}
	double Calc() const;
};


class SubNode :public BinaryNode{
public:
	SubNode(Node* left, Node* right) : BinaryNode(left, right){}
	double Calc() const;
};


class MultiplyNode :public BinaryNode{
public:
	MultiplyNode(Node* left, Node* right) : BinaryNode(left, right){}
	double Calc() const;
};


class DivideNode :public BinaryNode{
public:
	DivideNode(Node* left, Node* right) : BinaryNode(left, right){}
	double Calc() const;
};


class UminusNode :public UnaryNode{
public:
	UminusNode(Node* child) :UnaryNode(child){}
	double Calc() const;
};
#endif