#include<iostream>
#include<vector>
using namespace std;

//����һ����һ�����ϵĴ��麯��������ͱ���Ϊ������
class Shape{
public:
	virtual void Draw() = 0;
	//��̨���������������Ҫ����Ϊ����������
	//����̬�������������������Ϊ����������ʱ��������������������������
	//�������������ص��ǣ��������ڸ��൱�У�ͨ��virtual������������֮��
	//����ͨ�������ָ����ȥָ������Ķ���Ȼ��ͨ��delete�Ӹ���ָ��Ϳ����ͷŵ�����Ķ���
	virtual ~Shape(){
		cout << "~Shape..." << endl;
	}
};

class Circle :public Shape{
public:
	//���һ��������Ҳ��ʵ�ִ��麯������ô���������Ҳ����˳����࣬�򣬴��麯����ʵ�־�Ҫ�������������������
	void Draw(){
		cout << "Circle::Draw()..." << endl;
	}
	~Circle(){
		cout << "~Circle..." << endl;
	}
};

class Square :public Shape{
public:
	void Draw(){
		cout << "Square::Draw()..." << endl;
	}
	~Square(){
		cout << "~Square..." << endl;
	}
};

class Rectangle:public Shape{
public:
	void Draw(){
		cout << "Rectangle::Draw()..." << endl;
	}
	~Rectangle(){
		cout << "~Rectangle..." << endl;
	}
};

void DrawAllShape(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it){
		//������������൱��һ�µĹ۵�������)(*it) = Shape*
		//�������û�н��ú�������Ϊ���麯������ô����ͻ��������������Ļ���Draw
		//�����������Ǵ��麯������ô������ǻ���ָ��ָ����������麯������
		(*it)->Draw();
	}
}

void DeleteAllShape(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it){
		delete(*it);
		//*it���൱��Shape*,��ʵ��ָ�����һ�����������ͨ���ĳ���������������������ǿ�������
		//�ȵ��������������������Ȼ���ٵ��ó���������������������Ͳ������ڴ�й¶�ķ���
	}
}

//ʵ��һ���򵥵Ĺ���ģʽ
class ShapeFactory{
public:
	static Shape* CreateShape(const string& name){
		Shape* ps;
		if (name == "Circle"){
			ps = new Circle;
		}
		else if (name == "Square"){
			ps = new Square;
		}
		else if (name == "Rectangle"){
			ps = new Rectangle;
		}
		return ps;
	}
};
int main(){

	vector<Shape*> v;
	Shape* ps;
	//ps = new Circle;
	//v.push_back(ps);
	//ps = new Square;
	//v.push_back(ps);

	Shape* ps;
	ps = ShapeFactory::CreateShape("Circle");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Square");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Rectangle");
	v.push_back(ps);

	DrawAllShape(v);
	DeleteAllShape(v);
	return 0;
}