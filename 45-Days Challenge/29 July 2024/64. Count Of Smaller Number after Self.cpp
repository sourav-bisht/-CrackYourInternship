class Solution {
public:
    void merge(int left, int right, int mid, vector<pair<int,int>> &a, vector<int> &count)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<pair<int,int>> L(n1);
        vector<pair<int,int>> R(n2);
        for( int i = 0; i<n1; i++ )
        {
            L[i] = a[left+i];
        }
        for( int j = 0; j<n2; j++)
        {
            R[j] = a[mid+1+j];
        }
        int i = 0, j = 0, k = left, rightCount = 0;

        while( i<n1 && j<n2 )
        {
            if( L[i].first <= R[j].first )
            {
                count[L[i].second] += rightCount;
                a[k] = L[i];
                k++;
                i++;
            }
            else
            {
                rightCount++;
                a[k] = R[j];
                k++;
                j++;
            }
        }
        while( j<n2 )
        {
            a[k++] = R[j++];
        }
        while( i<n1 )
        {
            count[L[i].second] += rightCount;
            a[k++] = L[i++];
        }

    }
    void mergeSort(int left, int right, vector<pair<int,int>> &a, vector<int> &count)
    {
        if( left < right )
        {
            int mid = (left+right)/2;
            mergeSort(left,mid,a,count);
            mergeSort(mid+1,right,a,count);
            merge(left,right,mid,a,count);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++ )
        {
            a[i] = {nums[i],i};
        }

        int left = 0;
        int right = n-1;
        vector<int> count(n,0);
        mergeSort(left,right,a,count);
        count[n-1] = 0;
    return count;
    }
};
