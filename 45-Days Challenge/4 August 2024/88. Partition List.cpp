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
    ListNode* partition(ListNode* head, int x) {
        ListNode *temp = head;
        ListNode *temp2 = NULL;
        ListNode *newhead = NULL;
        ListNode *flag = NULL;
        while( temp != NULL )
        {
            if( flag == NULL && temp->val >= x )
            {
                flag = temp;
            }
            else if( temp->val < x )
            {
                ListNode *dummy = new ListNode(temp->val);
                if( newhead == NULL )
                {
                    newhead = dummy;
                    temp2 = newhead;
                }
                else
                {
                    temp2->next = dummy;
                    temp2 = temp2->next;
                }
            }
        temp = temp->next;
        }

        temp = flag;
        while( temp != NULL )
        {
            if( temp->val >= x )
            {
                ListNode *dummy = new ListNode(temp->val);
                if( newhead == NULL )
                {
                    newhead = dummy;
                    temp2 = newhead;
                }
                else
                {
                    temp2->next = dummy;
                    temp2 = temp2->next;
                }
            }
        temp = temp->next;
        }
    return newhead;
    }
};
