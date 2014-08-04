class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* pfast = head;
		ListNode* pslow = head;
		do{
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast==NULL)
				return NULL;
			pslow = pslow->next;
		}while(pfast != pslow);
        pfast = head;
		while(pfast != pslow)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		return pfast;
    }
};