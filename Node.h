#ifndef _NODE_H_
#define _NODE_H_


class Node
{
public:
	//����������Ҫ��������������Ϊ���麯��������delete����ָ��ʱ��������û������������
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


//��Ԫ����ڵ�,�������һ�������࣬��Ϊ��������֪������ξ���ؽ������㣬ֻ�мӼ��˳����Ǿ����
class BinaryNode :public Node{
public:
	BinaryNode(Node* left, Node* right) :left_(left), right_(right){}

	~BinaryNode();
protected:
	Node* const left_;
	Node* const right_;
};

//һԪ����ڵ�
class UnaryNode :public Node{
public:
	UnaryNode(Node* child) :child_(child){}
	~UnaryNode();
	//�ͷź���������ݳ�Ա
	//��ʱ�����̳���Node�����е�Calc���Ǵ���ģ�˵���������ʵ�����������Calc�����������Ҳ�ǳ�����
protected:
	Node* const child_;
};


//AddNode�̳���BinaryNode�����Ĺ��캯��Ҫ���û���Ĺ��캯��
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