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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = NULL;
        ListNode *temp = NULL;
        while( head != NULL )
        {
            ListNode *dummy = new ListNode(head->val);
            if( newHead == NULL && dummy->val != val )
            {
                newHead = dummy;
                temp = newHead;
            }
            else if( dummy->val != val )
            {
                temp->next = dummy;
                temp = temp->next;
            }
            head = head->next;
        }
    return newHead;
    }
};
