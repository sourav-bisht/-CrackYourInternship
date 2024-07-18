class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans;
        map[nums[0]] = 0;
        for( int i = 1; i<nums.size(); i++ )
        {
            int remaining = target - nums[i];
            if( map.find(remaining) != map.end() )
            {
                ans.push_back(i);
                ans.push_back(map[remaining]);
                break;
            }
            map[nums[i]] = i;
        }
    return ans;
    }
};
