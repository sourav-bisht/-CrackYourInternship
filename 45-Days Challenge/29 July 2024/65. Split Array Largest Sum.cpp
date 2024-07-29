class Solution {
public:
    int checkFunc( vector<int> &nums, int mid, int k )
    {
        int count = 1;
        int sum = 0;
        int n = nums.size();
        for( int i = 0; i<n; i++ )
        {
            sum += nums[i];
            if( sum > mid )
            {
                count ++;
                sum = nums[i];
            }
        }
    return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(); 
        int left = INT_MIN;
        int right = 0;
        if( k > n )
        {
            return 0;
        }
        for( int i = 0; i<n; i++ )
        {
            right = right + nums[i];
            if( nums[i] > left )
            {
                left = nums[i];
            }
        }
        cout<<right<<endl;
        int result = right;
        while( left <= right )
        {
            int mid = (left+right)/2;

            int check = checkFunc(nums,mid,k);
             
            if( check > k )
            {
                left = mid + 1;
            }
            else
            {
                result = min(result,mid);
                right = mid - 1;
            }
        }
    return result;
    }
};
