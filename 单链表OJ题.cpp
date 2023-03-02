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
//思路一：
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	while (cur)
	{
		//翻转
		cur->next = prev;
		//迭代往后走
		prev = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}
	return prev;
//思路二：取原链表中的节点，头插到newhead新链表中
	//ListNode* cur = head;
	//ListNode* newhead = NULL;
	//while (cur)//如果链表为NULL根本不会进入循环
	//{
	//	ListNode* next = cur->next;
	//	//头插
	//	cur->next = newhead;
	//	newhead = cur;
	//	//迭代
	//	cur = next;
	//}
	//return newhead;
}
//链表的中间节点 - 快慢指针法
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* fast, *slow;
	slow = fast = head;
	//每一次让slow走一步，fast走两步
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//链表中倒数第K个节点
struct ListNode* FindKthToTail1(struct ListNode* head, int k)
{
	struct ListNode* slow, *fast; 
	slow = fast = head;
	//让fast先走k步
	//for (int i = 0; i < k; i++)
	//{
	//    if (fast == NULL)
	//    {
	//	      return NULL;
	//    }
	//	fast = fast->next;
	//}
	while (k--)//走了k步
	{
		//为了防止k>链表的长度,当K大于链表的长度的时候，即便遍历完整个链表，也找不到k的节点
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//然后让fast和slow一起走
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
struct ListNode* FindKthToTail2(struct ListNode* head, int k)
{
	struct ListNode* slow, *fast;
	slow = fast = head;
	//让fast先走k-1步
	//for (int i = 0; i < k-1; i++)
	//{
	//    if (fast == NULL)
	//    {
	//	      return NULL;
	//    }
	//	fast = fast->next;
	//}
	while (--k)//让fast先走k-1步
	{
		if (fast->next == NULL)
		{
			return NULL;
		}
		fast = fast->next; 
	}
	//然后让fast和slow一起走
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = NULL, *tail = NULL;
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	//下面的这一对if else是针对刚开始head和tail都是NULL的时候，这样进行了之后，在while循环里就可以不用在判断head是否为空
	//if (l1->data < l2->data)
	//{
	//	head = tail = l1;
	//	l1 = l1->next;
	//}
	//else
	//{
	//	head = tail = l2;
	//	l2 = l2->next;
	//}
	//当然，上面这一段代码完全可以用新建一个哨兵位来代替操作，意义都是一样的
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//这样之后就说明head和tail不是空指针了，而是一个真实存在的哨兵节点
	//哨兵节点的存在，可以让我在不改变头指针的情况下从而进行操作
	//但是，由于哨兵节点是malloc出来的，所以在最后必须要将其free掉，所以我必须用一个新的头指针来接收并返回
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
	}
	//最终，会剩下部分链表没接上，那么在这里我就可以直接一次性全部接上
	if (l1 != NULL)
	{
		tail->next = l1;
	}
	if (l2 != NULL)
	{
		tail->next = l2;
	}
	/*return head;这行代码是对应用if else来操作第一次的情况的*/
	struct ListNode* newhead = head->next;
	free(head);
	head = NULL;
	//这三行代码是对应用哨兵节点操作时来返回的
	return newhead;
}
//现有一个链表头指针pHead,给一定值x，编写一段代码将所有小于x的节点排在其余节点之前，且不改变原来数据顺序，返回新的链表
struct ListNode* partition(struct ListNode* pHead, int x)
{
	//用两个哨兵位分别接收小于x的节点和大于x的节点冰沟城新的链表
	struct ListNode* lessHead, *lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	struct ListNode* greaterHead, *greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterTail->next = NULL;
	struct ListNode* cur = pHead;
	while (cur)
	{
		if (cur->data < x)
		{
			lessTail->next = cur;//让lessTail连接上cur
			lessTail = lessTail->next;//然后lessTail换到新的位置
		}
		else
		{
			greaterTail->next = cur;//让greaterTail连接上cur
			greaterTail = greaterTail->next;//然后greaterTail换到新的位置
		}
		cur = cur->next;//最后让cur往下一个节点走，把这句代码放出来执行，是因为不管是if还是else最后我都需要执行这句代码
		//cur是在原来的链表上走动，而lessTail和greaterTail都是在启迪赢得哨兵位领导的链表上移动的
	}
	//由于最后一次连接时我的倒数第二个数可能大于最后一个数，然后greaterHead的尾部就会连着lessHead的最后一个数
	//于是，连接两个新链表时，就可能发生闭环，从而导致死循环，所以我需要将greaterHead的尾部置空，然后再连接两个分链表
	greaterHead->next = NULL;
	lessTail->next = greaterHead->next;
	//然后现在需要返回新的链表，但这个新的链表又不能包含自己设定的哨兵位，所以我需要用新的指针来承担返回值的这个任务
	//况且，我的哨兵位是malloc出来的，最终都是要free的，所以只能用新的指针来接收
	struct ListNode* newhead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	//lessTail和greaterHead是不能释放的，因为lessTail还骑着连接作用，其后面还存在有效数据，一旦释放链表后面的数据就没了
	return newhead;
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
	//struct ListNode* head1 = removeElements(n1, 7);
	struct ListNode* head2 = reverseList(n1);
	return 0;
}
