/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = 0;
		int len2 = 0;
		ListNode * p = l1;
		ListNode * q = l2;
		while (p->next != NULL)
		{
			len1++;
			p = p->next;

		}
		while (q->next != NULL)
		{
			len2++;
			q = q->next;
		}
		if (len1 >= len2)
		{
			for (int i = 0; i < len1 - len2; i++)
			{
				q->next = new ListNode(0);
				q = q->next;
			}
		}
		else
		{
			for (int i = 0; i < len2 - len1; i++)
			{
				p->next = new ListNode(0);
				p = p->next;
			}
		}
		p = l1;
		q = l2;
		bool count = false;
		int i = 0;
		ListNode * l3 = new ListNode(-1);
		ListNode * w = l3;
		while (p != NULL || q != NULL)
		{
			i = count + q->val + p->val;
			w->next = new ListNode(i % 10);
			w = w->next;
			p = p->next;
			q = q->next;
			count = i >= 10 ? true : false;
		}
		if (count)
		{
			w->next = new ListNode(1);
			w = w->next;
		}
		return l3->next;




	}
};



//不对齐，直接相加
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode * head = new ListNode(-1);
		ListNode * h = head;

		int sum = 0;
		bool carry = false;
		while (l1 != NULL || l2 != NULL)
		{
			sum = 0;
			if (l1 != NULL)
			{
				sum += l1->val;
				l1 = l1->next;

			}
			if (l2 != NULL)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			if (carry)
			{
				sum++;
			}
			h->next = new ListNode(sum % 10);
			h = h->next;
			carry = sum >= 10 ? true : false;
		}
		if (carry)
		{
			h->next = new ListNode(1);
		}
		return head->next;
	}
};