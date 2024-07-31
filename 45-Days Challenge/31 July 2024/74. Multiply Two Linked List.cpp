class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        if( first == NULL || second == NULL )
        {
            return 0;
        }
        long long MOD = pow(10,9)+7;
        long long num1 = 0, num2 = 0;
        
        while( first || second )
        {
            if( first )
            {
                num1 = ( (num1*10)%MOD + (first->data%MOD) ) % MOD;
                first = first->next;
            }
            if( second )
            {
                num2 = ( (num2*10)%MOD + (second->data%MOD) ) % MOD;
                second = second->next;
            }
        }
        
        long long product = (num1%MOD * num2%MOD) % MOD;
    return product;
    }
};
