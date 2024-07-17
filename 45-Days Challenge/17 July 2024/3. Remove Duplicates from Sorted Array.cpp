class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 1;
        int n = nums.size();

        while( i<n )
        {
            if( nums[k] != nums[i] )
            {
                nums[k+1] = nums[i];
                k++;
            }
            i++;
        }
    return k+1;
    }
};
