class Solution {
public:
    string minWindow(string s, string t) {
        if( t.length() > s.length() ) return "";
        int n = s.length();

        unordered_map<char,int> map;
        for( char &ch : t )
            map[ch]++;

        int count = t.length();
        int i = 0, j = 0;
        int minWindow = INT_MAX;
        int start_i = 0;

        while( j<n )
        {
            char ch = s[j];
            if( map[ch] > 0 )
                count--;

            map[ch]--;

            while( count == 0 )
            {
                int currWindow = (j-i+1);
                if( minWindow > currWindow )
                {
                    minWindow = currWindow;
                    start_i = i;
                }

                map[s[i]]++;
                if( map[s[i]] > 0 )
                {
                    count++;
                }
            ++i;
            }
        ++j;
        }
        string ans;
        minWindow == INT_MAX ? (ans = "") : (ans = s.substr(start_i,minWindow));
        return ans;
    }
};
