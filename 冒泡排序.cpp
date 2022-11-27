#include<stdio.h>
void bubble_sort(int arr[], int sz)//利用函数改变函数外部的变量需要用到指针和解引用才可以。
{
	int i = 0;
	for (i = 0; i < sz; i++)//先确定要冒泡排序的趟数，趟数=sz-1 
	{
		int j = 0;
		int flag = 1; //建立flag这个变量是为了应对有序数组的情况,先假设flag=1 
		for (j = 0; j < sz - i - 1; j++)//然后确定每一趟冒泡排序所要进行对比的次数， 
		{
			if (arr[j]>arr[j + 1])//由于有序时，arr[j]<arr[j+1]因此条件不成立，该if语句不进行，于是跳到了下面那个if语句 
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag=0; 
			}
		}
		if(1==flag)//由于如果每次上面那个if语句都会进行的话，每次进行结束，flag都会是0，如果不进行，则flag=1，也就是此次对比的元素有序 
		{
			break;
		}
	 }
}
int main()
{
	int arr[] = { 9, 7, 8, 6, 5, 1, 3, 2, 4, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//sz只能在主函数中计算好，因为如果是传给函数当中再去进行计算时，传进去的数组只是首元素的地址，但本身的sizeof(arr)传进去的是数组整个本身 
	//arr是数组，对数组传参时，实参传给形参，形参是实参的一份临时拷贝，实际上传递过去的时数组arr首元素的地址即：&arr[0]
	int i = 0;
	bubble_sort(arr,sz);//冒泡排序函数，目的是实现冒泡排序
	for (i = 0; i < sz; i++)// 
	{
		printf("%d ", arr[i]);//利用循环一一打印冒泡排序的结果
	}
	return 0;
}
/*
int i=0;
for(i=1;i<=sz-1;i++)
{
	int j=0;
	int flag=1;
	for(j=1;j<=sz-i-1;j++)
	{
		if(arr[i]>arr[i+1])
		{
			int temp=arr[i];
			arr[i]=arr[i+1];
			arr[i+1]=arr[i];
			flag=0;
		}
	}
	if(flag==1)
	{
		break;
	}
 } 
 */
 //这一段代码是冒泡排序最重要的部分，只要将这部分代码熟悉了，冒泡排序对你来说，只差个敲键盘的时间！！！ 
