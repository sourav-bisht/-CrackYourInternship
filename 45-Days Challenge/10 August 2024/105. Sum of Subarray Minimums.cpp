class Solution {
public:
    vector<int> NSE(vector<int> &arr)
    {
        vector<int>nse;
        int n = arr.size();
        stack<int> st;
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
    vector<int> PSE(vector<int> &arr)
    {
        vector<int>pse;
        int n = arr.size();
        stack<int> st;
        for( int i = 0; i<n; i++ )
        {
            while( !st.empty() && arr[st.top()] > arr[i])
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
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0;
        int MOD = 1e9+7;
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> pse = PSE(arr);

        for( int i = 0; i<n; i++ )
        {
            int left = i-pse[i];
            int right = nse[i]-i;
            sum = (sum+(left*1LL*right*arr[i])%MOD)%MOD;
        }
    return sum;
    }
};
