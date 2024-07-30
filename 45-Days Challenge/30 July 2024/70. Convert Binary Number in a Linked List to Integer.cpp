class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int count = 0;
        ListNode *temp = head;
        int ans = 0;
        while( temp != NULL )
        {
            count++;
            temp = temp->next;
        }

        temp = head;
        while( temp != NULL )
        {
            if( temp->val == 1 )
            {
                ans += pow(2,count-1);
            }
            count--;
            temp = temp->next;
        }
    return ans;  
    }
};
