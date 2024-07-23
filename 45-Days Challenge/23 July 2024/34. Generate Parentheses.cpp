class Solution {
private:
    void parentheses(vector<string> &ans, string &curr, int n, int open, int close )
    {
        if( curr.length() == 2*n )
        {
        ans.push_back(curr);
        return;
        }
        if( open < n )
        {
            curr.push_back('(');
            parentheses(ans,curr,n,open+1,close);
            curr.pop_back();
        }
        if( close < open )
        {
            curr.push_back(')');
            parentheses(ans,curr,n,open,close+1);
            curr.pop_back();
        }
    return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        int open = 0;
        int close = 0;
        parentheses(ans,curr,n,open,close);
        return ans;
    }
};
