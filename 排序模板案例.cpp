#include<iostream>
using namespace std;
//案例描述：
//1.利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//2.排序规则为从小到大，排序算法为选择排序
//3.分被利用char数组和int数组进行测试
//两数交换模板
template<typename T>
void MySwap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;

}

//排序函数模板
template<typename T>
void MySort(T arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		int max = i;//先认定i就是最大值的下标，通过下面比较在改变就行
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[max] < arr[j])//注意注意，这里是和查找到的 j 进行比较，不是和原来的 i 比较，本来max = i，如果下标写i还有什么意义
			{
				//认定的最大值 比 遍历出的数值要小，说明遍历出的数值才是最大值，那么就将新的最大值进行交换往前放
				max = j;//更新最大值下标
			}
		}
		
		if (max != i)
		{
			//此时说明在上面的for循环过程中，max的大小已经被改变了，那么就要将其所对应的数据也改过来
			MySwap(arr[max], arr[i]);
		}
	}
}

//数组打印函数模板
template<typename T>
void MyPrint(T arr[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1(){
	char chararr[] = "bdceaf";
	int len = sizeof(chararr) / sizeof(char);
	MySort(chararr, len);

	MyPrint(chararr, len);

}

void test2(){
	int arr[] = { 1, 4, 3, 5, 2, 6, 8, 7, 9 };
	MySort(arr, sizeof(arr) / sizeof(int));
	MyPrint(arr, sizeof(arr) / sizeof(int));
}

int main(){

	test1();
	test2();
	return 0;
}