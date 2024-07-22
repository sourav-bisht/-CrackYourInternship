class Solution {
public:
    bool isValid(string s) {
        bool ans = false;
        int n = s.length();
        stack<char> st;
        for( int i = 0; i<n; i++ )
        {
            if( st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']') )
            {
                return false;
            }
            if( s[i] == '(' || s[i] == '{' || s[i] == '[' )
            {
                st.push(s[i]);
            }
            else if( (st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']') || (st.top() == '{' && s[i] == '}'))
            {
                st.pop();
            }
            else if( (st.top() == '(' && s[i] != ')') || (st.top() == '{' && s[i] != '}') || (st.top() == '[' && s[i] != ']') )
            {
                return false;
            }
        }
        if( st.empty() ) ans = true;
    return ans;
    }
};
