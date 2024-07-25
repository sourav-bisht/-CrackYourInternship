class Solution {
public:
    int calculate(string s) {
        int n = s.length();

        string stack;
        string temp1 = "", temp2 = "";
        for( int i = 0; i<n; i++ )
        {
            if( !stack.empty() && (stack.back() == '*' || stack.back() == '/') )
            {
                temp1 = "", temp2 = "";
                char op = stack.back();
                stack.pop_back();
                while( !stack.empty() && stack.back() != '-' && stack.back() != '+' )
                {
                    temp1 = stack.back() + temp1;
                    stack.pop_back();
                }
                while( i<n && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' )
                {
                    temp2 = temp2 + s[i];
                    i++;
                }
                if( op == '*')
                {
                    stack += to_string( (stoi(temp1))*(stoi(temp2)) );
                }
                else if( op == '/' )
                {
                    stack += to_string( (stoi(temp1))/(stoi(temp2)) );
                }
            }
            if( i<n )   stack.push_back(s[i]);
        }
        cout<<stack<<endl;
        int ans = 0;
        int prevOp = 0;
        n = stack.size();
        temp1 = "";
        for( int i = 0; i<n; ++i )
        {
            if( stack[i] != '+' && stack[i] != '-' )
            {
                temp1 = temp1 + stack[i];
            }
            if( (stack[i] == '+' || stack[i] == '-') || ( i == n-1) )
            {
                if( prevOp == 0 )
                    ans = stoi(temp1);
                else if( prevOp == 1)
                    ans = ans + stoi(temp1);
                else if( prevOp == -1)
                    ans = ans - stoi(temp1);
                temp1 = "";
                stack[i] == '+' ? (prevOp = 1) : (prevOp = -1);
            }
        }
    return ans;
    }
};
