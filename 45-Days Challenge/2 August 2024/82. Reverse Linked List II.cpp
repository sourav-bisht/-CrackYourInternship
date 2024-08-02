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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head;
        ListNode *temp1 = NULL;
        ListNode *temp2 = NULL;
        ListNode *start = NULL;
        ListNode *prev = NULL;
        int count = 1;
        while( temp != NULL )
        {
            if( count == left )
            {
                start = temp;
                temp1 = prev;
            }
            if( count == right )
            {
                temp2 = temp->next;
                temp->next = NULL;
                break;
            }
            count++;
            prev = temp;
            temp = temp->next;
        }

        start = reverseList(start);
        if( temp1 != NULL )
        {
            temp1->next = start;
        }
        else if( temp1 == NULL )
        {
            head = start;
        }
        
        temp = start;
        while( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = temp2;
    return head;
    }
};
