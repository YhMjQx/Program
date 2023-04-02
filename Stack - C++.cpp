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
	//构造函数	-  C++中初始化指针为NULL可以用0初始化
	Stack() :head_(0), size_(0){

	}

	//析构函数
	~Stack(){
		Link* tmp;
		while (head_){
			tmp = head_;
			head_= head_->next_;
			delete tmp;
		}
		size_ = 0;
	}
	//入栈
	void Push(const int data){
		Link* node = new Link(data, head_);
		node->next_ = head_;
		head_ = node;
		++size_;
	}

	//判断栈是否为空
	bool IsEmpty(){
		return (size_ == 0);
	}

	//出栈
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
//用C++实现栈，避免名称冲突
//数据可进行封装，能保护内部数据结构不遭受外部破坏，更加安全
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