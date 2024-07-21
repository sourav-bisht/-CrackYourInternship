class Solution {
  public:
    void permutate(vector<int> &arr, set<vector<int>> &ans, vector<bool> &visited, vector<int> &temp )
    {
        if( temp.size() == arr.size() )
        {
            ans.insert(temp);
            return;
        }
        
        for( int i = 0; i<arr.size(); i++ )
        {
            if( !visited[i] )
            {
                visited[i] = true;
                temp.push_back(arr[i]);
                permutate(arr,ans,visited,temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
    return;
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(),arr.end());
        vector<bool> visited(n,false);
        vector<int> temp;
        set<vector<int>>ans;
        vector<vector<int>> finalAns;
        permutate(arr,ans,visited,temp);
        
        for( auto it : ans )
        {
            finalAns.push_back(it);
        }
        
        return finalAns;
    }
};
