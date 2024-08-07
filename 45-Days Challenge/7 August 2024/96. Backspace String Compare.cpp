class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int k = 0;
        int l = 0;
        for( int i = 0; i<s.length(); i++ )
        {
            if( s[i] == '#' )
            {
                if( k != 0 ) k--;
                continue;
            }
            s[k] = s[i];
            k++;
        }
        for( int i = 0; i<t.length(); i++ )
        {
            if( t[i] == '#' )
            {
                if( l != 0 ) l--;
                continue;
            }
            t[l] = t[i];
            l++;
        }
    return s.substr(0,k) == t.substr(0,l);
    }
};
