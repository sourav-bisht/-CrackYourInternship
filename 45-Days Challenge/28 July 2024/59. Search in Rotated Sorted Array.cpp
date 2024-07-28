class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int index = -1;

        while( left <= right )
        {
            int mid = (left+right)/2;
            if( nums[mid] == target )
            {
                index = mid;
                break;
            }
            else if( nums[left] > nums[mid] )
            {
                if( target >= nums[mid] && target <= nums[right] ) left = mid + 1;
                else right = mid - 1;
            }
            else 
            {
                if( target >= nums[left] && target <= nums[mid] ) right = mid - 1;
                else left = mid + 1;
            }
        }

    return index;
    }
};
