class Solution {
  public:
    bool isPossible(long long a[], long long b[], int n, long long k) {
        sort(a,a+n);
        sort(b,b+n,greater<int>());
        
        long long sum = 0;
        for( int i = 0; i<n; i++ )
        {
            sum = a[i];
            sum += b[i];
            if( sum < k )
            {
                return false;
            }
        }
    return true;
    }
};
