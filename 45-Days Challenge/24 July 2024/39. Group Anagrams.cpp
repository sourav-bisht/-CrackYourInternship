class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> hashMap;
        int n = strs.size();
        vector<vector<string>> ans;
        vector<string> tempAns;
        for( int i = 0; i<n; i++ )
        {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            hashMap[temp].push_back(i);
        }

        for( auto it : hashMap )
        {
            vector<int> indices = it.second;
            tempAns.clear();
            for( auto jt : indices )
            {
                tempAns.push_back(strs[jt]);
            }
            ans.push_back(tempAns);
        }
    return ans;
    }
};
