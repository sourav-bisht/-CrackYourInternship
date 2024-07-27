class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<int>ans(2);
        if( x < arr[0] )
        {
            ans[0] = -1;
        }
        if( x > arr[n-1] )
        {
            ans[1] = -1;
        }
        
        int prev_max = INT_MIN;
        int prev_min = INT_MAX;
        
        for( int i = 0; i<n; i++)
        {
            if( arr[i] > prev_max )
            {
                prev_max = arr[i];
                if( prev_max > x )
                    break;
                ans[0] = prev_max;
            }
        }
        for( int i = (n-1); i>=0; i--)
        {
            if( arr[i] < prev_min )
            {
                prev_min = arr[i];
                if( prev_min < x )
                    break;
                ans[1] = prev_min;
            }
        }
    return ans;
    }
};
