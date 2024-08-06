class Solution {
  public:
    Node* divide(Node* head) {
        Node *newhead = NULL;
        Node *temp = NULL;
        Node *curr = head;
        Node *prev = NULL;
        int flag = 0;
        Node *concat = NULL;
        while( curr )
        {
            if( (curr->data)%2 == 0 )
            {
                if( newhead == NULL )
                {
                    newhead = curr;
                    temp = newhead;
                }
                else
                {
                    temp->next = curr;
                    temp = temp->next;
                }
                if( prev )  
                {
                    prev->next = curr->next;
                    curr = prev->next;
                }
                else
                {
                    curr = curr->next;  
                }
            }
            else
            {
                if( flag == 0 )
                {
                    concat = curr;
                    flag = 1;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    temp->next = concat;
    return newhead;
    }
};
