class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = NULL;
        ListNode *newHead = NULL;
        int value = 0;
        int carry = 0;

        while( l1 != NULL && l2 != NULL )
        {
            int sum = (carry+l1->val+l2->val);
            if( sum > 9 )
            {
                value = sum % 10;
                carry = sum/10;
            }
            else
            {
                value = sum;
                carry = 0;
            }
            ListNode *dummy = new ListNode(value);
            if( newHead == NULL )
            {
                newHead = dummy;
                temp = newHead;
            }
            else
            {
                temp->next = dummy;
                temp = temp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while( l1 != NULL )
        {
            int sum = (carry + l1->val);
            if( sum > 9 )
            {
                value = sum % 10;
                carry = sum / 10;
            }
            else 
            {
                value = sum;
                carry = 0;
            }
            ListNode *dummy = new ListNode(value);
            temp->next = dummy;
            temp = temp->next;
            l1 = l1->next;
        }
        while( l2 != NULL )
        {
            int sum = (carry + l2->val);
            if( sum > 9 )
            {
                value = sum % 10;
                carry = sum / 10;
            }
            else 
            {
                value = sum;
                carry = 0;
            }
            ListNode *dummy = new ListNode(value);
            temp->next = dummy;
            temp = temp->next;
            l2 = l2->next;
        }
        if( carry == 1 )
        {
            ListNode *dummy = new ListNode(carry);
            temp->next = dummy;
            temp = temp->next;
        }
    return newHead;
    }
};
