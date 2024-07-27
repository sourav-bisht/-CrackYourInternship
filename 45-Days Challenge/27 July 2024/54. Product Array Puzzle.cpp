class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> ans(n);
        long long int produc = 1;
        int flag = 0;
        for( int i = 0; i<n; i++ )
        {
            if( nums[i] != 0)
                produc *= nums[i];
            else if( nums[i] == 0 )
                flag ++;
        }
        
        for( int i = 0; i<n; i++)
        {
            if( flag == 1 )
            {
                if( nums[i] == 0 )
                    ans[i] = produc;
                else
                    ans[i] = 0;
            }
            else if( flag > 1)
            {
                ans[i] = 0;
            }
            else
                ans[i] = produc/nums[i];
        }
    return ans;
    }
};
