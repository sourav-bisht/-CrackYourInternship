class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        int n = s.length();
        for( int i = (n-1); i>=0; --i )
        {
            if( s[i] != ' ' )
            {
                temp = s[i] + temp;
            }
            if( s[i] == ' ' || i == 0 )
            {a
                ans = ans + temp;
                temp = "";
            }
            if( !ans.empty() && ans.back() != ' ' )
            {
                ans.push_back(' ');
            }
        }
        if( ans.back() == ' ') ans.pop_back();
    return ans;
    }
};
