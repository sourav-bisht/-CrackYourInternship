class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);
        dp[0] = true;
        for( int i = 0; i<n; i++ )
        {
            if(dp[i])
            {
                int farthest_jump = min(i+nums[i],n-1);
                for( int j = i+1; j<=farthest_jump; ++j )
                {
                    dp[j] = true;
                }
            }
        }
    return dp[n-1];
    }
};
