	ListNode* reverseList(ListNode* head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* tmphead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return tmphead;
	}