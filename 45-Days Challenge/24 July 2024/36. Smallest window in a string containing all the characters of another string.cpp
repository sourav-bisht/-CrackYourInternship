class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        if( p.length() > s.length() ) return "-1";
        
        int n = s.size();
        vector<int> mp(256,0);
        for( char ch : p )
        {
            mp[ch]++;
        }
        
        int minWindow = INT_MAX;
        int i = 0, j = 0;
        int start_i = 0;
        int count = p.length();
        
        while( j<n )
        {
            char ch = s[j];
            if( mp[ch] > 0 )
            {
                count--;
            }
            mp[ch]--;
            
            while( count == 0 )
            {
                int currWindow = (j-i+1);
                if( minWindow > currWindow )
                {
                    minWindow = currWindow;
                    start_i = i;
                }
                
                mp[s[i]]++;
                if( mp[s[i]] > 0 )
                {
                    count++;
                }
            ++i;
            }
        ++j;
        }
        string ans;
        minWindow == INT_MAX ? (ans = "-1") : (ans = s.substr(start_i,minWindow));
    return ans;
    }
};
