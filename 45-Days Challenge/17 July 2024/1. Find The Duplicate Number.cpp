class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do              //Each element of nums is a valid index;
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while( slow != fast );

        slow = 0;

        while( slow != fast )
        {
            slow = nums[slow];
            fast = nums[fast];
        }
    return slow;
    }
};
