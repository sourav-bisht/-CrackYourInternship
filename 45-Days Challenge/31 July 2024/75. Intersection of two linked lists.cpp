class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode *temp = headA;
        while( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = headA;
        ListNode *slow = headB;
        ListNode *fast = headB;
        ListNode *ans = NULL;
        while( fast != NULL )
        {
            fast = fast->next;
            if( fast != NULL )
            {
                slow = slow->next;
                fast = fast->next;
            }
            if( slow == fast )
            {
                slow = headB;
                break;
            }
        }
        if( fast == NULL )
        {
            temp = headA;
            while( temp->next != headA )
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return NULL;
        }
        while( fast != slow )
        {
            slow = slow->next;
            fast = fast->next;
        }
        ans = slow;

        temp = headA;
        while( temp->next != headA )
        {
            temp = temp->next;
        }
        temp->next = NULL;
    return ans;
    }
};
