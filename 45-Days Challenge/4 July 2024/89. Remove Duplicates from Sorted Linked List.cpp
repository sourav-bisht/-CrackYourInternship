/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prv = head;
        ListNode *nxt = NULL;
        if( head != NULL)
            nxt = head->next;
        ListNode *temp = NULL;
        ListNode *newhead = NULL;

        while( prv != NULL )
        {
            if( nxt == NULL || prv->val != nxt->val )
            {
                ListNode *dummy = new ListNode(prv->val);
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
            while( nxt != NULL && prv->val == nxt->val )
            {
                nxt = nxt->next;
            }
            prv = nxt;
            if( prv == NULL ) break;
            nxt = nxt->next;
        }
    return newhead;
    }
};
