class Solution{
  public:
    vector<int> getNSL(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> NSL(n);
        for( int i = 0; i<n; i++ )
        {
            while( !st.empty() && heights[st.top()] >= heights[i] )
            {
                st.pop();
            }
            if( st.empty() )
            {
                NSL[i] = -1;
            }
            else
            {
                NSL[i] = st.top();
            }
            st.push(i);
        }
    return NSL;
    }
    vector<int> getNSR(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> NSR(n);
        for( int i = (n-1); i>=0 ; i-- )
        {
            while( !st.empty() && heights[st.top()] >= heights[i] )
            {
                st.pop();
            }
            if( st.empty() )
            {
                NSR[i] = n;
            }
            else
            {
                NSR[i] = st.top();
            }
            st.push(i);
        }
    return NSR;
    }
    
    int findMaxArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> NSR(n);
        vector<int> NSL(n);
        NSR = getNSR(heights);
        NSL = getNSL(heights);
        
        vector<int> width(n);
        for( int i = 0; i<n; i++ )
        {
            width[i] = NSR[i] - NSL[i] - 1;
        }
        
        int maxArea = 0;
        for( int i = 0; i<n; i++ )
        {
            int a = heights[i] * width[i];
            maxArea = max(maxArea,a);
        }
    return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> heights(m);
        for( int i = 0; i<m; i++ )
        {
            heights[i] = M[0][i];
        }
        int maxArea = findMaxArea(heights);
        
        for( int row = 1; row<n; row++ )
        {
            for( int col = 0; col<m; col++)
            {
                if( M[row][col] == 0 )
                {
                    heights[col] = 0;
                }
                else
                {
                    heights[col]++;
                }
            }
            maxArea = max(maxArea,findMaxArea(heights));
        }
    return maxArea;
    }
};
