class Solution {
  public:
    int checkFunc(int n, int arr[], long long mid)
    {
        long long sum = 0;
        int count = 1;
        for( int i = 0; i<n; i++ )
        {
            sum += arr[i];
            if( sum > mid )
            {
                sum = arr[i];
                count++;
            }
        }
    return count;
    }
    
    long long findPages(int n, int arr[], int m) {
        int left = INT_MIN;
        int right = 0;
        
        if( n < m )
        {
            return -1;
        }
        for( int i = 0; i<n; i++ )
        {
            right += arr[i];
            if( left < arr[i] )
            {
                left = arr[i];
            }
        }
        long long result = right;
        while( left <= right )
        {
            long long mid = (left + right)/2;
            
            int check = checkFunc(n,arr,mid);
            
            if( check > m )
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
