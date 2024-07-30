class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if( head == NULL )
        {
            return head;
        }
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;

        while( temp2 != NULL )
        {
            if( temp1->val == temp2->val )
            {
                temp1->next = NULL;
            }
            else if( temp1->val != temp2->val )
            {
                temp1->next = temp2;
                temp1 = temp1->next;
            }
        temp2 = temp2->next;
        }
    return head;
    }
};
