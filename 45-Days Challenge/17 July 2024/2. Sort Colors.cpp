class Solution {
public:
    void sortColors(vector<int>& nums) {
        int indZero = 0;
        int indTwo = nums.size()-1;
        int i = 0;
        while( i <= indTwo )
        {
            if( nums[i] == 0 )
            {
                swap(nums[i],nums[indZero]);
                ++indZero;
                ++i;
            }
            else if( nums[i] == 2 )
            {
                swap( nums[i], nums[indTwo] );
                --indTwo;
            }
            else ++i;
        }
    }
};
