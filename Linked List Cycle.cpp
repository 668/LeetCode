class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* pfast = head;
		ListNode* pslow = head;
		do{
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast!=NULL)
				pfast=pfast->next;
			if(pfast==NULL)
				return false;
			pslow = pslow->next;
		}while(pfast != pslow);			//when fast meet slow ,it means  the list has cycle
		return true;
    }
};