class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for( auto it : lists )
        {
            ListNode *temp = it;
            while( temp != NULL )
            {
                pq.push({temp->val,temp});
                temp = temp->next;
            }
        }

        ListNode *newhead = NULL;
        ListNode *temp = NULL;

        while( !pq.empty() )
        {
            if( newhead == NULL )
            {
                newhead = pq.top().second;
                temp = newhead;
            }
            else
            {
                temp->next = pq.top().second;
                temp = temp->next;
            }
            pq.pop();
        }
    return newhead;
    }
};
