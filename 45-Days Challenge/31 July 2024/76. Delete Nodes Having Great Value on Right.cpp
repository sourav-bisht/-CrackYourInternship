class Solution
{
    public:
    Node *reverseLinkedList(Node* head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *nxt = NULL;
        while( curr != NULL )
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    return prev;  
    }
    
    Node *compute(Node *head)
    {
        head = reverseLinkedList(head);
        
        int prevMax = INT_MIN;
        Node *newHead = NULL;
        Node *temp = NULL;
        while( head != NULL )
        {
            if( head->data >= prevMax )
            {
                Node *dummy = new Node(head->data);
                if( newHead == NULL )
                {
                    newHead = dummy;
                    temp = newHead;
                }
                else
                {
                    temp->next = dummy;
                    temp = temp->next;
                }
                prevMax = head->data;
            }
        head = head->next;
        }
    return reverseLinkedList(newHead);
    }
    
};
