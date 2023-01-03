#include<stdio.h>
int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1-*(int *)e2;
}
void Swap(char*my_q1,char*my_q2,int width)
{
	int i=0;
	for(i=0;i<width;i++)
	{
	char tmp=*my_q1;
	*my_q1=*my_q2;
	*my_q2=tmp;
	my_q1++;
	my_q2++;
	}
}
void my_qsort(void* base,int sz,int width,void (*cmp)(const void* e1,const void* e2))
{
	int i=0;
	for(i=0;i<sz-1;i++)
	{
		int j=0;
		for(j=0;j<sz-1-i;j++)
		{
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				Swap((char*)base+j*width,(char*)base+(j+1)*width,width);
			}
		}
	}
}
void test()
{
	int arr[]={0,2,4,6,8,1,3,5,7,9};
	int sz=sizeof(arr)/sizeof(arr[0]);
	my_qsort(arr,sz,sizeof(arr[0]),cmp_int);
	int i=0;
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	test();
	return 0;
 } 
