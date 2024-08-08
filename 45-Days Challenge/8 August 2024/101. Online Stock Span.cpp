class StockSpanner {
public:
    vector<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;

        if( !st.empty() )
        {
            int n = st.size();
            for( int i = n-1; i>=0; i-- )
            {
                if( st[i] > price )
                {
                    break;
                }
                count++;
            }
        }
        st.push_back(price);
        return count;
    }
};

