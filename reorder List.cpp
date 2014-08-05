#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tmphead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmphead;
	}
	void reorderList(ListNode *head){
		if (head == NULL || head->next == NULL)
			return;
		ListNode *pslow = head;
		ListNode *pfast = head;
		while (pfast != NULL)
		{
			if (pfast != NULL)
				pfast = pfast->next;
			if (pfast != NULL)
				pfast = pfast->next;
			if (pfast == NULL)
				break;
			pslow = pslow->next;
		}
		ListNode* head2 = pslow->next;
		pslow->next = NULL;
		head2 = reverseList(head2);
		ListNode *p1 = head;
		ListNode *p2 = head2;
		ListNode *tmp = NULL;
		while (p1 != NULL && p2 != NULL)
		{
			tmp = p1->next;
			p1->next = p2;
			p1 = tmp;
			tmp = p2->next;
			p2->next = p1;
			p2 = tmp;
		}
	}
};
