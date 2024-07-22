class Solution {
private:
    void nextSmallestLeft(vector<int> heights, vector<int> &NSL, int n)
    {
        stack<int> st;
        int index;
        for( int i = 0; i<n; ++i )
        {
            while( !st.empty() && heights[st.top()] >= heights[i] ) st.pop();
            if( st.empty() )
            {
                index = -1;
            }
            else
            {
                index = st.top();
            }
            st.push(i);
            NSL.push_back(index);
        }
    }
    void nextSmallestRight(vector<int> heights, vector<int> &NSR,int n)
    {
        stack<int> st;
        int index;
        for(int i = n-1; i>=0; --i )
        {
            while( !st.empty() && heights[st.top()] >= heights[i] ) st.pop();
            if( st.empty() )
            {
                index = n;
            }
            else
            {
                index = st.top();
            }
            st.push(i);
            NSR.push_back(index);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL;
        vector<int> NSR;
        nextSmallestLeft(heights,NSL,n);
        nextSmallestRight(heights,NSR,n);
        int ans = 0;
        reverse(NSR.begin(),NSR.end());
        for( int i = 0; i<n; ++i )
        {
            int temp = (NSR[i]-(NSL[i]+1) )* heights[i];
            ans = max(ans,temp);
        }
    return ans;
    }
};
