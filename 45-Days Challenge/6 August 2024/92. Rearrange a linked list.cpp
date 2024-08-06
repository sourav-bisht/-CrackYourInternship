class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        if( head == NULL || head->next == NULL )
        {
            return;
        }
        
        Node *odd = head;
        Node *even = head->next;
        Node *evenhead = head->next;
        
        while( even != NULL && even->next != NULL )
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
    }
};
