//移除单链表中的元素
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
//移除数据为val的链表
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->data == val)
		{
			//万一要删的数据在链表的头部怎么办
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			//此时由于prev不是NULL所以我便可以将prev使用->
			else
			{
				prev->next = cur->next;//跳过val，让指针指向val的下一个链接
				free(cur);
				cur = prev->next;//让cur往后走
			}
		}
		//cur->data ！= val此时让cur往后走
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
//给你单链表的头节点head，请你反转链表，并返回翻转后的链表
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = cur->next;
	while (cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if (next->next!=NULL)
			next = next->next;
	}
	return prev;
}
int main()
{
	//方便快速调试链表
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->data = 7;
	n2->data = 7;
	n3->data = 7;
	n4->data = 7;
	n5->data = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;


	struct ListNode* head = removeElements(n1, 7);

}
