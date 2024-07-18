class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        int j,k;
        vector<vector<int> > ans;
        while( i < (n-2) )
        {
            if( i>0 && nums[i] == nums[i-1])
            {
                ++i;
                continue;
            }
            int j = i+1;
            int k = n-1;
            while( j<k )
            {
                if( nums[i]+nums[j]+nums[k] < 0 )
                {
                    j++;
                }
                else if( nums[i]+nums[j]+nums[k] > 0 )
                {
                    --k;
                }
                else
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    ++j;
                    --k;
                    while( j<k && nums[j] == nums[j-1] ) ++j;
                    while( k>j && nums[k] == nums[k+1] ) --k;
                }
            }
            ++i;
        }
    return ans;
    }
};
