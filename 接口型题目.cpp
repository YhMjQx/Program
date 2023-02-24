//�ӿ�����Ŀ
//1.����Ҫдͷ�ļ����������ȵ�
//2.�ύ���Ժ󣬻��OJ���������Ѿ�׼���õĴ���ϲ����ٱ�������
//����������ͨ��������������
//�����һ����ͨ������ֵ�õģ�Ҳ�п���������Ͳ���
#include<stdio.h>

//��Ŀ����һ��nums��һ��ֵval������Ҫԭ���Ƴ�������ֵ����val��ֵ��������������³���
//eg��nums[6] = { 1, 3, 3, 4, 3, 5 }, val = 3;
//˼·һ��һһ�������飬��ͷ��ʼ��������val��ʱ�򣬽�val֮�����������ǰ�ƶ�һλ
	//ֻ������ʱ��ʱ�临�Ӷ���O(N^2)����Ϊ������������ʱ�������д󲿷ֻ���ȫ������val
//˼·��������һ���µ����飬��ͷ���������Ȼ�󽫲���val��ֵ����������µ��������棬�ٰ�tmp������ȥ
	//��ʱʱ�临�Ӷ���O(N)���ռ临�Ӷ���O(N)
//˼·�����������±꣬����src��dest��srcȥ��nums�����в�����val��ֵ������destָ���λ��ȥ��Ȼ��src++��dest++
	//��ʱʱ�临�Ӷ���O(N)���ռ临�Ӷ���O(1)
//int removeElement(int* nums, int numsize, int val)
//{
//	int src = 0, dest = 0;
//	while (src < numsize)
//	{
//		if (nums[src] != val)
//		{
//			nums[dest] = nums[src];
//			src++;
//			dest++;
//		}
//		else
//		{
//			src++;
//		}
//	}
//	return dest;
//}

//��Ŀ������һ����������nums������ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ��ֻ����һ�Σ�����ɾ����������³���
//eg:nums = {0,0,1,1,1,2,2,3,3,4}
//int removeDuplicates(int* nums, int numsize)
//{
	//������Ҫ�ж������Ƿ�Ϊ�գ����Ϊ�ո�������Ҫִ��
//	if (numsize == 0)
//		return 0;
//	int dest = 0, i = 0, j = 1;
//	while (j < numsize)
//	{
//		if (nums[i] == nums[j])
//		{
//			j++;
//		}
//		if (nums[i] != nums[j])
//		{
//			nums[dest] = nums[i];
//			dest++;
//			i = j;
//			j++;
//		}
//	}
//	nums[dest] = nums[i];
//	dest++;
//	return dest;
//}
//int main()
//{
//	int arr[3] = { 1, 1, 2 };
//	int len = removeDuplicates(arr,3);
//	printf("%d\n", len);
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}


//��Ŀ����������ϲ�,��������������ϲ���֮�󣬻��ܱ���һ����˳��
//eg�����룺nums1 = { 1, 2, 3, 0, 0, 0 };    nums2 = { 2, 5, 6 };m��nums1����Ч���ݵĸ�����n��nums2��Ԫ�ظ���
//�����[1,2,2,3,5,6]
void merge(int* nums1, int* nums2, int m, int n)//ʱ�临�Ӷ���O(M+N)���ռ临�Ӷ���O(1)
{
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}
	while (end1 < 0 && end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}
int main()
{
	int nums1[6] = { 1, 2, 3, 0, 0, 0 };
	int nums2[3] = { 2, 5, 6 };
	merge(nums1, nums2, 3, 3);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", nums1[i]);
	}
	return 0;
}