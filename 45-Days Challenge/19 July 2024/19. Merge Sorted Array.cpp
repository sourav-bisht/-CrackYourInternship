class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = nums1.size();
        int i = len-n-1;
        int j = len-1;
        if( m == 0 )
        {
            nums1 = nums2;
            return;
        }
        if( n == 0 )
        {
            return;
        }

        while( i>=0 )
        {
            swap(nums1[i],nums1[j]);
            --j;
            --i;
        }

        i = len-m;
        j = 0;
        int k = 0;
        while( i<len && j<n )
        {
            if( nums1[i] < nums2[j] )
            {
                nums1[k++] = nums1[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }
        while( i<len )
        {
            nums1[k++] = nums1[i++];
        }
        while( j<n )
        {
            nums1[k++] = nums2[j++];
        }
    }
};
