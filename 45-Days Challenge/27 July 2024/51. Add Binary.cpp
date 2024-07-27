class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        if( n == 0 || a == "0" )
        {
            return b;
        }
        if( m == 0 || b == "0" )
        {
            return a;
        }
        
        int i = (n-1), j = m-1;
        int carry = 0;
        string ans = "";
        while( i>=0 && j>=0 )
        {
            int a_num = a[i] - '0';
            int b_num = b[j] - '0';
            int sum = a_num + b_num + carry;
            if( sum >= 2 )
            {
                carry = 1;
                sum -= 2;
            }
            else
            {
                carry = 0;
            }
            char ch = sum + '0';
            ans = string(1,ch) + ans;
            --i;
            --j;
        }
        while( i>=0 )
        {
            int sum = carry + (a[i] - '0');
            if( sum == 2 )
            {
                carry = 1;
                sum = 0;
            }
            else
            {
                carry = 0;
            }
            char ch = sum + '0';
            ans = string(1,ch) + ans;
            --i;
        }
        while( j>=0 )
        {
            int sum = carry + (b[j]-'0');
            if( sum == 2 )
            {
                carry = 1;
                sum = 0;
            }
            else
            {
                carry = 0;
            }
            char ch = sum + '0';
            ans = string(1,ch) + ans;
            --j;
        }

        if( carry == 1 )
        {
            char ch = carry + '0';
            ans = string(1,ch) + ans;
        }
    return ans;
    }
};
