class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i;
        int left = 0;
        int right = (n-1);
        int up = 0;
        int down = (m-1);
        vector<int> ans;

        while( left <= right )
        {
        if( up <= down )
        {
            i = left;
            while( i<=right)
            {
                ans.push_back(matrix[up][i]);
                ++i;
            }
            ++up;
        }

        if( left <= right )
        {
            i = up;
            while( i<=down )
            {
                ans.push_back(matrix[i][right]);
                ++i;
            }
            --right;
        }

        if( up<=down )
        {
            i = right;
            while( i>=left )
            {
                ans.push_back(matrix[down][i]);
                --i;
            }
            --down;
        }

        if( left<=right )
        {
            i = down;
            while( i>=up )
            {
                ans.push_back(matrix[i][left]);
                --i;
            }
            ++left;
        }
        }
        return ans;
    }
};
