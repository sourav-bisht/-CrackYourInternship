class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        ListNode *temp = head;

        while( temp != NULL )
        {
            minHeap.push(temp->val);
            temp = temp->next;
        }
        ListNode *newhead = NULL;
        temp = NULL;
        while( !minHeap.empty() )
        {
            ListNode *dummy = new ListNode(minHeap.top());
            minHeap.pop();

            if( newhead == NULL )
            {
                newhead = dummy;
                temp = newhead;
            }
            else
            {
                temp->next = dummy;
                temp = temp->next;
            }
        }
    return newhead;
    }
};
