class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || head->next==NULL) return head;

        ListNode* pA = head, *pB = head;

        while( pA && pB && pB->next && pB->next->next )
        {
            pA = pA->next;
            pB = pB->next->next;
        }        
        pB= pA->next;
        pA->next = NULL;
        pA = head;


        pA = sortList(pA);
        pB = sortList(pB);       
        return MergeSortedList(pA, pB);

    }

    ListNode* MergeSortedList(ListNode *pA, ListNode* pB)
    {
        if( !pB ) return pA;
        if( !pA ) return pB;

        ListNode* head,*merge;
        if( pA->val < pB->val )
        {
            head = pA ;
            pA = pA->next;
        }
        else
        {
            head = pB;
            pB = pB->next;
        }

        merge = head;
        while( pA && pB )
        {
            if(pA->val < pB->val) 
            {
                merge->next = pA;
                merge=merge->next;
                pA= pA->next;
            }
            else
            {
                merge->next = pB;
                merge=merge->next;
                pB= pB->next;
            }
        }

        if( pA ) merge->next = pA;
        if( pB ) merge->next = pB;

        return head;       
    }
};