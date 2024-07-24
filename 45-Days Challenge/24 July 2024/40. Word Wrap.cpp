class Solution {
public:
    int dp[505][2005];
    int rec(int i, int rem, vector<int> nums, int k)
    {
        if( i == nums.size() )
        {
            return 0;
        }
        if( dp[i][rem] != -1 )
        {
            return dp[i][rem];
        }
        int ans;
        if( nums[i] > rem )
        {
            ans = (rem+1)*(rem+1) + rec(i+1,k-nums[i]-1,nums,k);
        }
        else 
        {
            int choice1 = (rem+1)*(rem+1) + rec(i+1,k-nums[i]-1,nums,k);
            int choice2 = rec(i+1,rem-nums[i]-1,nums,k);
            ans = min(choice1,choice2);
        }
        dp[i][rem] = ans;
    return ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,k,nums,k);
    return ans;
    } 
};
