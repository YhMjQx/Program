#include<stdio.h>
//static还可以修饰全局变量，本来全局变量可以在整个源文件(即多个文件)中使用，但若在单个源文件中用static修饰了之后，则这个全局变量只能在这个文件中使用 
	void test()//调用一个函数，小括号叫做函数的操作符
	{
		static int a = 0;//static使局部变量a的生命周期突破了，变成了一个静态的局部变量，也就是说使得该局部变量突破生命周期 
		a++;             //以至于可以让该局部变量在{}存在 
		printf("a=%d ", a);
	}
	int main()
	{
		int i = 0;
		while (i < 5)
		{
			test();//调用了test函数
				i++;
				printf("i=%d \n", i);
		}
		return 0;
	}
