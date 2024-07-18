class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for( int i = 0; i<(n-3); ++i )
        {
            if( i>0 && nums[i] == nums[i-1] ) continue;
            for( int j = i+1; j<(n-2); ++j )
            {
                int k = j+1;
                int l = n-1;
                while( k<l )
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if( sum > target )
                    {
                        --l;
                    }
                    else if( sum < target )
                    {
                        ++k;
                    }
                    else
                    {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ++k;
                        --l;
                        ans.push_back(temp);
                        while( k<l && nums[k] == nums[k-1] ) ++k;
                        while( l>k && nums[l] == nums[l+1] ) --l;
                    }
                }
                while( j < (n-1) && nums[j] == nums[j+1] ) ++j;
            }
        } 
    return ans;  
    }
};
