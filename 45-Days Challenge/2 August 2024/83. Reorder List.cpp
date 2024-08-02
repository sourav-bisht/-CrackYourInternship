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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while( curr != NULL )
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    return prev;
    }
    void reorderList(ListNode* head) {
        if( head->next == NULL || head->next->next == NULL )
        {
            return;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while( fast != NULL && fast->next != NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = reverseList(slow->next);
        slow->next = NULL;
        ListNode *temp1 = head;
        ListNode *temp2 = head2;
        ListNode *next1 = NULL;
        ListNode *next2 = NULL;

        do
        {
            next1 = temp1->next;
            next2 = temp2->next;
            temp1->next = temp2;
            temp2->next = next1;
            temp1 = next1;
            temp2 = next2;
        }while( temp2 != NULL );
    }
};
