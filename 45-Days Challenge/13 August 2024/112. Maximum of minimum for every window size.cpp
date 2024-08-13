class Solution
{
    public:
    vector<int> PSE(int arr[],int n)
    {
        stack<int>st;
        vector<int> pse;
        for( int i = 0; i<n; i++ )
        {
            while( !st.empty() && arr[st.top()] >= arr[i] )
            {
                st.pop();
            }
            if( st.empty() )
            {
                pse.push_back(-1);
            }
            else
            {
                pse.push_back(st.top());
            }
            st.push(i);
        }
    return pse;
    }
    
    vector<int> NSE(int arr[],int n)
    {
        stack<int>st;
        vector<int> nse;
        for( int i = (n-1); i>=0; i-- )
        {
            while( !st.empty() && arr[st.top()] >= arr[i] )
            {
                st.pop();
            }
            if( st.empty() )
            {
                nse.push_back(n);
            }
            else
            {
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(),nse.end());
    return nse;
    }
    
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> pse = PSE(arr,n);
        vector<int> nse = NSE(arr,n);
        
        vector<int> ans(n,0);
        
        for( int i = 0; i<n; i++ )
        {
            int left = pse[i];
            int right = nse[i];
            for( int j = 0; j<(right-left-1); j++ )
            {
                if( ans[j] < arr[i] )
                {
                    ans[j] = arr[i];
                }
            }
        }
    return ans;
    }
};
