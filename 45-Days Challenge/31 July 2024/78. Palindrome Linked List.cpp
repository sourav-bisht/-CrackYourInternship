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
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool ans = true;
        while( fast != NULL && fast->next != NULL )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reve = reverseList(slow);
        ListNode *temp = head;
        while( reve != NULL )
        {
            if( reve->val != temp->val )
            {
                ans = false;
                break;
            }
            reve = reve->next;
            temp = temp->next;
        }
    return ans;
    }
};
