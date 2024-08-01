class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node *newhead = NULL;
        Node *helper = NULL;
        Node *temp = head;
        while( temp != NULL )
        {
            Node *dummy = new Node(temp->val);
            if( newhead == NULL )
            {
                newhead = dummy;
                helper = newhead;
            }
            else
            {
                helper->next = dummy;
                helper = helper->next;
            }
            mp[temp] = helper;
            temp = temp->next;
        }

        temp = head;
        Node *temp2 = newhead;

        while( temp != NULL )
        {
            if( temp->random != NULL )
            {
                temp2->random = mp[temp->random];
            }
            else
            {
                temp2->random = NULL;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    return newhead;
    }
};
