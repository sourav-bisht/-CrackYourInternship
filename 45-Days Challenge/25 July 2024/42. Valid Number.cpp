class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if( n == 1 && !isdigit(s[0]) )
            return false;
        else if( n == 1 && isdigit(s[0]) )
            return true;

        unordered_map<char,int> visited;
        visited['+'] = 0;
        visited['-'] = 0;
        visited['e'] = 0;
        visited['E'] = 0;
        visited['.'] = 0;

        bool ans = true;
        for(int i = 0; i<n; i++ )
        {
            char ch = s[i];
            if( !isdigit(ch) )
            {
                if( visited.find(ch) == visited.end() )
                {
                    ans = false;
                    break;
                }
                else if( ch == '+' || ch == '-' )
                {
                    if( i==(n-1) )
                    {
                        ans = false;
                        break;
                    }
                    if( visited['+'] + visited['-'] >= 2 )
                    {
                        ans = false;
                        break;
                    }
                    else if( i>0 && i<(n-1) && (s[i-1] != 'e' && s[i-1] != 'E') )
                    {
                        ans = false;
                        break;
                    }
                    else if( (visited['+'] == 0 && visited['-'] == 0) || (s[i-1] == 'e' || s[i-1] == 'E') )
                    {
                        visited[ch]++;
                    } 
                }
                else if( ch == 'e' || ch == 'E' )
                {
                    if( (i==0) || (i==(n-1)) )
                    {
                        ans = false;
                        break;
                    }
                    else if( !isdigit(s[i-1]) && s[i-1] != '.' )
                    {
                        ans = false;
                        break;
                    }
                    else if( s[i-1] == '.' && i-1 == 0 )
                    {
                        ans = false;
                        break;
                    }
                    else if( !isdigit(s[i+1]) && (s[i+1] != '+' && s[i+1] != '-') )
                    {
                        ans = false;
                        break;
                    }
                    else if( visited['e'] != 0 || visited['E'] != 0 )
                    {
                        ans = false;
                        break;
                    }
                    else 
                    {
                        visited[ch]++;
                    }
                }
                else if( ch == '.' )
                {
                    if( visited['e'] != 0 || visited['E'] != 0 )
                    {
                        ans = false;
                        break;
                    }
                    else if( i>0 && !isdigit(s[i-1]) && (visited['+'] + visited['-'] > 1) )
                    {
                        ans = false;
                        break;
                    }
                    else if( visited['.'] != 0 )
                    {
                        ans = false;
                        break;
                    }
                    else if( i==n-1 && !isdigit(s[i-1]) )
                    {
                        ans = false;
                        break;
                    }
                    else if( i>0 && i<n-1 && !isdigit(s[i-1]) && !isdigit(s[i+1]))
                    {
                        ans = false;
                        break;
                    }
                    else
                    {
                        visited[ch]++;
                    }
                }
            }
        }
    return ans;
    }
};
