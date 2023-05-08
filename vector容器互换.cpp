#include<iostream>
#include<vector>
using namespace std;

void Printvector(vector<int>& v){
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] <<" ";
	}
	cout << endl;
}

//基本使用
void test1(){
	vector<int> v1;

	cout << "交换前：" << endl;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}
	cout << "v1:" << "";
	Printvector(v1);
	
	vector<int>v2;
	for (int i = 10; i>0; --i){
		v2.push_back(i);
	}
	cout << "v2:" << "";
	Printvector(v2);

	cout << "交换后：" << endl;

	v2.swap(v1);
	cout << "v1:" << "";
	Printvector(v1);
	cout << "v2:" << "";
	Printvector(v2);

}

//实际用途
//巧用swap可以收缩内存空间
void test2(){
	vector<int >v1;
	for (int i = 0; i < 393939; ++i){
		v1.push_back(i);
	}

	cout << "v1的容量为： " << v1.capacity() << endl;
	cout << "v1的大小为： " << v1.size() << endl;

	v1.resize(3939);//给v1重新指定一个大小
	cout << "v1的容量为： " << v1.capacity() << endl;
	cout << "v1的大小为： " << v1.size() << endl;
	//此时我们会发现，v1这个容器大小的确是变小了，但是v1的容量还是那么大，说明现在我们在浪费内存空间
	//那么我们该如何回收这片被浪费的内存空间呢？接下来看我操作

	vector<int>(v1).swap(v1);
	cout << "v1的容量为： " << v1.capacity() << endl;
	cout << "v1的大小为： " << v1.size() << endl;

	//vector<int> - 这是一个类型，然后用这个类型创建了一个匿名容器
	//而这个匿名容器使用v1拷贝构造得来的，所以匿名容器的大小以及其内部的数据是一样的
	//那么就说明匿名容器的容量和大小是3939
	//然后用这个匿名容器调用了swap这个函数，对匿名容器和v1进行互换
	//所以现在的v1容量就缩小到了3939，而且其内部的数据也不会改变
	//那么这个匿名容器就对应的是原来v1对应的空间
	//但是编译器当执行完这句代码之后，发现这有一个匿名容器，就会立马将匿名容器销毁
	//所以我们也不用对这个匿名容器操作，编译器会帮我们操作的
}

int main(){
	//test1();
	test2();
	return 0;
}