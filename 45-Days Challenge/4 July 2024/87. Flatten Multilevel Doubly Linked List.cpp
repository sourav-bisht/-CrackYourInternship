/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void dfs(Node* temp)
    {
        Node *temp2 = temp->next;
        temp->next = temp->child;
        temp->child->prev = temp;
        temp->child = NULL;
        temp = temp->next;
        while( temp->next != NULL )
        {
            if( temp->child != NULL )
            {
                dfs(temp);
            }
        temp = temp->next;
        }
        temp->next = temp2;
        if( temp2 != NULL ) temp2->prev = temp;
    return;
    }
    Node* flatten(Node* head) {
        
        Node *temp = head;
        while( temp != NULL )
        {
            if( temp->child != NULL )
            {
                dfs(temp);
            }
        temp = temp->next;
        }
    return head;
    }
};
