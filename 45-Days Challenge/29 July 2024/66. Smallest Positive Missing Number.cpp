class Solution
{
    public:
    int missingNumber(int arr[], int n) 
    { 
        sort(arr,arr+n);
        int prevSmallest;
        int smallestPositive = 1;
        for( int i = 0; i<n; i++ )
        {
            if( arr[i] > 0 && arr[i] == smallestPositive )
            {
                prevSmallest = smallestPositive;
                smallestPositive += 1;
            }
            else if( arr[i] <= 0 || arr[i] == prevSmallest )
            {
                continue;
            }
            else
            {
                break;
            }
        }
    return smallestPositive;
    } 
};
