class Solution {
private:
    void countPair( vector<int> &nums, int left, int right, int mid, int &ans )
    {
        int j = mid+1;
        for( int i = left; i<=mid; ++i )
        {
            while( j<=right && nums[i] > (long long)2 * nums[j] ) ++j;
            ans += j-(mid+1);
        }
    }
    void merge(vector<int> &nums, int left, int right, int mid)
    {
        int n1 = mid-left+1;
        int n2 = right-mid;
        vector<int> L(n1);
        vector<int> R(n2);
        int k = 0;
        for( int i = left; i<=mid; i++ )
        {
            L[k++] = nums[i]; 
        }
        k = 0;
        for( int i = mid+1; i<=right; i++ )
        {
            R[k++] = nums[i];
        }

        int i = 0, j = 0;
        k = left;
        while( i<n1 && j<n2 )
        {
            if( L[i] < R[j] )
            {
                nums[k++] = L[i++];
            }
            else
            {
                nums[k++] = R[j++];
            }
        }
        while( i<n1 )
        {
            nums[k++] = L[i++];
        }
        while( j<n2 )
        {
            nums[k++] = R[j++];
        }
    }
    void mergeSort( vector<int> &nums, int left, int right, int &ans )
    {
        if( left < right )
        {
        int mid = (left+right)/2;

        mergeSort(nums,left,mid,ans);
        mergeSort(nums,mid+1,right,ans);
        countPair(nums,left,right,mid,ans);
        merge(nums,left,right,mid);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        int left = 0;
        int right = nums.size()-1;
        mergeSort(nums,left,right,ans);

        return ans;
    }
};
