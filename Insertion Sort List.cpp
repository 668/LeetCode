#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL)
			return head;
		ListNode *cur = head->next;
		ListNode *tmp = NULL;
		while (cur != NULL)
		{
			tmp = head;
			while (tmp->val < cur->val && tmp != cur)
				tmp = tmp->next;
			if (tmp != cur)
			{
				int first = cur->val;
				int second;
				while (tmp != cur)
				{
					second = tmp->val;
					tmp->val = first;
					first = second;
					tmp = tmp->next;
				}
				cur->val = first;
			}
			cur = cur->next;
		}
		return head;
	}
};