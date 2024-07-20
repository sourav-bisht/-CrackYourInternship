class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        int ans = 0;
        for( int i : nums )
        {
            sum += i;
            int rem = sum-k;
            if( prefixSum.find(rem) != prefixSum.end() )
            {
                ans += prefixSum[rem];
            }
            prefixSum[sum]++;
        }
    return ans;
    }
};
