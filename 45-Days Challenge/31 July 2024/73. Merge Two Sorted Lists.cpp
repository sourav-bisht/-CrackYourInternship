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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        ListNode *temp = NULL;

        while( list1 != NULL && list2 != NULL )
        {
            ListNode *dummy = new ListNode();
            if( list1->val <= list2->val )
            {
                dummy->val = list1->val;
                list1 = list1->next;

                if( head == NULL )
                {
                    head = dummy;
                    temp = head;
                }
                else
                {
                    temp->next = dummy;
                    temp = temp->next;
                }
            }
            else
            {
                dummy->val = list2->val;
                list2 = list2->next;

                if( head == NULL )
                {
                    head = dummy;
                    temp = head;
                }
                else
                {
                    temp->next = dummy;
                    temp = temp->next;
                }  
            }
        }
        while( list1 != NULL )
        {
            ListNode *dummy = new ListNode();
            dummy->val = list1->val;
            list1 = list1->next;

                if( head == NULL )
                {
                    head = dummy;
                    temp = head;
                }
                else
                {
                    temp->next = dummy;
                    temp = temp->next;
                } 
        }
        while( list2 != NULL )
        {
            ListNode *dummy = new ListNode();
            dummy->val = list2->val;
            list2 = list2->next;

                if( head == NULL )
                {
                    head = dummy;
                    temp = head;
                }
                else
                {
                    temp->next = dummy;
                temp = temp->next;
                }
        }
    return head;
    }
};
