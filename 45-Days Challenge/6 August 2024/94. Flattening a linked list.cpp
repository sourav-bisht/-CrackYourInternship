class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        priority_queue< pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
        Node *temp = root;
        
        while( temp )
        {
            if( temp->bottom )
            {
                Node *temp2 = temp;
                while( temp2 )
                {
                    pq.push({temp2->data,temp2});
                    temp2 = temp2->bottom;
                }
            }
            else
            {
                pq.push({temp->data,temp});
            }
            temp = temp->next;
        }
        
        Node *newhead = NULL;
        temp = NULL;
        
        while( !pq.empty() )
        {
            if( newhead == NULL )
            {
                newhead = pq.top().second;
                temp = newhead;
            }
            else
            {
                temp->bottom = pq.top().second;
                temp = temp->bottom;
            }
        pq.pop();
        }
    return newhead;
    }
};
