class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool ans = false;

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
                ans = true;
                break;
            }
        }
    return ans;
    }
};
