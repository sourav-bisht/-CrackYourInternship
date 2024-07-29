int checkFunc(int n, vector<int> &stalls, int k, int &mid)
{
    int count = 1;
    int prevMin = stalls[0];
    for( int i = 1; i<n; i++ )
    {
        if( (stalls[i] - prevMin) >= mid )
        {
            prevMin = stalls[i];
            count++;
        }
    }
return count;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    int left = 1;
    int right = stalls[n-1] - stalls[0];

    int ans = 1;
    while( left <= right )
    {
        int mid = (left+right)/2;

        int check = checkFunc(n,stalls,k,mid);

        if( check < k )
        {
            right = mid - 1;
        }
        else
        {
            ans = max(ans,mid);
            left = mid + 1;
        }
    }
    return ans;
}
