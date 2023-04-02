#include<iostream>
using namespace std; 
class Stack{
public:
	struct Link{
		int data_;
		Link* next_;
		Link(int data, Link* next) :data_(data), next_(next){

		}
	};
	//���캯��	-  C++�г�ʼ��ָ��ΪNULL������0��ʼ��
	Stack() :head_(0), size_(0){

	}

	//��������
	~Stack(){
		Link* tmp;
		while (head_){
			tmp = head_;
			head_= head_->next_;
			delete tmp;
		}
		size_ = 0;
	}
	//��ջ
	void Push(const int data){
		Link* node = new Link(data, head_);
		node->next_ = head_;
		head_ = node;
		++size_;
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool IsEmpty(){
		return (size_ == 0);
	}

	//��ջ
	bool Pop(/*int& data*/){
		if (IsEmpty()){
			return false;
		}
		Link* tmp = head_;
		/*data = head_->data_;*/
		head_ = head_->next_;
		delete tmp;
		return true;
	}
	void Display(){
		cout << head_->data_ << endl;
	}
private:
	Link* head_;
	int size_;
};
//��C++ʵ��ջ���������Ƴ�ͻ
//���ݿɽ��з�װ���ܱ����ڲ����ݽṹ�������ⲿ�ƻ������Ӱ�ȫ
int main(){
	Stack stack;
	int i;
	for (int i = 0; i < 5; i++){
		stack.Push(i);
	}
	while (!stack.IsEmpty()){
		stack.Display();
		stack.Pop();

		/*cout << i << " ";*/
	}
	cout << endl;
	return 0;
}