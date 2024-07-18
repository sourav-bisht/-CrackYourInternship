class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> remainder;
        remainder[0] = 1;
        int sum = 0;
        int result = 0;
        for( auto it : nums )
        {
            sum += it;
            int rem = sum%k;
            if( rem < 0 ) { rem += k; }

            if( remainder.find(rem) != remainder.end() )
            {
                result += remainder[rem];
                remainder[rem] += 1;
            }
            else
            {
                remainder[rem] = 1;
            }
        }
        return result;
    }
};
