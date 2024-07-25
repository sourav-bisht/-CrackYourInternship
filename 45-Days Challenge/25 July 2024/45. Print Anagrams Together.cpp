class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string,vector<pair<int,string>>> mp;
        int n= string_list.size();
        
        for( int i = 0; i<n; i++ )
        {
            string temp = string_list[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back({i,string_list[i]});
        }
        
        vector<vector<string>> ans;
        for( auto &it : mp )
        {
            vector<pair<int,string>> words;
            words = it.second;
            sort(words.begin(),words.end());
            vector<string> tempAns;
            for( auto &jt : words )
            {
                tempAns.push_back(jt.second);
            }
        ans.push_back(tempAns);
        }
    return ans;
    }
};
