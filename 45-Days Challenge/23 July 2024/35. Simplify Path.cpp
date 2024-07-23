class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        string temp = "";
        int n = path.length();
        for( int i = 1; i<n; i++ )
        {
            temp = temp + path[i];
            if( path[i] == '/' || (i+1) == n )
            {
                if( temp.back() == '/' ) temp.pop_back();
                if( temp != "." && temp != ".." && temp != "/" )
                {
                    ans += temp;
                    temp = "";
                }
                else if( temp == ".." )
                {
                    temp = "";
                    ans.pop_back();
                    while( !ans.empty() && ans.back() != '/' )
                    {
                        ans.pop_back();
                    }
                }
                else if( temp == "." )
                {
                    temp = "";
                    continue;
                }
            }
            if( ans.empty() || ans.back() != '/' )
            {
                ans.push_back('/');
            }
        }
    if( ans.length() > 1 && ans.back() == '/' ) ans.pop_back();
    return ans;
    }
};
