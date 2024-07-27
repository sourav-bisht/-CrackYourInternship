class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int num1 = nums[n-1];
        int num2 = nums[n-2];
        int num3 = nums[n-3];
        int num4 = nums[0];
        int num5 = nums[1];
        int ans1 = num1*num2*num3;
        int ans2 = num1*num4*num5;
    return max(ans1,ans2);
    }
};
