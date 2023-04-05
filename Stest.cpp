#include"String.h"
#include<stdio.h>
int main(){
	String s1("HYHYHY");
	char ch1 = s1[2];
	cout << ch1 << endl;
	char ch2 = s1[3];
	cout << ch2 << endl;
	//我们对[]的定义和实现用的是引用的返回值，这么做的好处是什么呢；
	//函数返回引用的好处是可以让函数放在"="左边给函数的结果进行赋值和改变，如下：
	s1[3] = 'H';
	s1.Display();
	s1[2] = 'Y';
	s1[3] = 'Y';
	s1.Display();
		//以上代码调用的都是non const 版本的operator[]

	const String s2("abcdef");
		//既然我的对象是const的，那么我就不希望我的对象被改变
		//所以我做出的改变就是给我的operator[]前面加上const
		//但为了防止重载不通过(因为编译器不能重载只是因为返回类型不同的函数)
		//所以我在函数最后也加上了const修饰，这样我的返回类型就是const引用，那么这里的s2[2]就是无法改变的
	char ch = s2[2];//可以将const char&的值赋给char
	//s2[2] = 'A';//但不能将char的值赋给const char&
	s2.Display(); 
		//这部分代码调用的是 const 版本的operator[]


	String s3("HHH");
	String s4("YYY ");
		//如果构造函数没有explicit修饰的话，这两句代码就相当于
		//String s3 = "HHH";
		//String s4 = "YYY";
	String s5 = s3 + s4;
	s3 += s4;
	s5.Display();
	s3.Display();
	cout << s3 << endl;

	
	String s6 = "YhMjQx " + s5 + "1314";
		//String s6 = "YhMjQx " + "1314" + s5;这个操作就不行了，因为我们并没有重载两个char*字符串相加的operator+()函数
		//因此，最前面的两个相加的至少其中一个要是对象,然后才可以转化
	s6.Display();

	String s7;
	cin >> s7;
	cout << s7 << endl;

	return 0;
}